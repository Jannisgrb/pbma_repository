// gtest_main.cpp
// Lesen Sie diesen Code nicht, ändern Sie ihn nicht.
// Vor dem Test Ihrer Anwendung wird dieser Code wiederhergestellt.
#include <iostream>
#include <cstdlib>

#include "gtest/gtest.h"

#include "alltest.h"

// the main program running all unit tests
GTEST_API_ int main(int argc, char** argv) {
    std::cout << "Running main() from gtest_main.cpp" << std::endl;
    testing::InitGoogleTest(&argc, argv);
    const auto ret = RUN_ALL_TESTS();
    return ret;
}

/// Memory checks
// Override new [] and delete [] as well as new and delete for tracing.
// Use two different stores for single (s) and array (a) allocations
// to catch some memory errors

// #define MEM_VERBOSE

// for all tests this is the maximum number of allocations for *all* unit tests
constexpr int SMAX_ALLOCS = 65536;
constexpr int AMAX_ALLOCS = 65536;

// extern declared in alltest.h
std::atomic<size_t> scurrent_alloc{0};
std::atomic<size_t> acurrent_alloc{0};
std::atomic<size_t> scurrent_freed{0};
std::atomic<size_t> acurrent_freed{0};
bool we_are_testing{false};
std::vector<int> sdouble_freed;
std::vector<int> adouble_freed;
std::vector<void*> sfreed_notalloc;
std::vector<void*> afreed_notalloc;

// part of the fixture class
int AllTest::scall;
int AllTest::acall;
int AllTest::sfreed;
int AllTest::afreed;

// pointers to allocated single chunks
static void* smemory[SMAX_ALLOCS];
// pointers to allocated array chunks
static void* amemory[AMAX_ALLOCS];
// size of allocated single chunks
static std::size_t smem_size[SMAX_ALLOCS];
// size of allocated array chunks
static std::size_t amem_size[AMAX_ALLOCS];
// whether single alloc has been freed
static bool smem_freed[SMAX_ALLOCS]{false};
// whether array alloc has been freed
static bool amem_freed[AMAX_ALLOCS]{false};
// count the double freed allocations
static int double_freed{0};
// count the freed but not allocated ptrs
static int freed_not_allocated{0};

static constexpr size_t LEFT_REDZONE_SIZE = 32;
static constexpr size_t RIGHT_REDZONE_SIZE = 64;
static constexpr char ZONE_VALUE = 0x55;
static void* allocate_memory(std::size_t s) {
    const std::size_t ss = LEFT_REDZONE_SIZE + s + RIGHT_REDZONE_SIZE;
    char* p = static_cast<char*>(malloc(ss));
#ifdef MEM_VERBOSE
    std::cout << "allocate_memory(" << s << "): " << static_cast<void*>(p)
              << std::endl;
#endif
    for (size_t i = 0; i < ss; ++i) {
        p[i] = ZONE_VALUE;
    }
    return static_cast<void*>(p + LEFT_REDZONE_SIZE);
}

static bool check_illegal_memory_write(void* buf, std::size_t s) {
    char* p = static_cast<char*>(buf) - LEFT_REDZONE_SIZE;
#ifdef MEM_VERBOSE
    std::cout << "check_memory(" << s << "): " << static_cast<void*>(p)
              << std::endl;
#endif
    for (size_t i = 0; i < LEFT_REDZONE_SIZE; ++i) {
        if (p[i] != ZONE_VALUE) {
            ADD_FAILURE() << " illegal access " << (LEFT_REDZONE_SIZE - i)
                          << " left of " << static_cast<void*>(p)
                          << " size=" << s;
            return false;
        }
    }
    for (size_t i = 0; i < RIGHT_REDZONE_SIZE; ++i) {
        if (p[LEFT_REDZONE_SIZE + s + i] != ZONE_VALUE) {
            ADD_FAILURE() << " illegal access " << (i + 1) << " right of "
                          << static_cast<void*>(p) << " size=" << s;
            return false;
        }
    }
    return true; // nothing as of now
}

bool check_illegal_memory_write(void* p) {
    // we do not know whether it is normal or array
    // search in both
    for (size_t i = 0; i < scurrent_alloc; ++i) {
        if (smemory[i] == p) {
            return check_illegal_memory_write(p, smem_size[i]);
        }
    }
    for (size_t i = 0; i < acurrent_alloc; ++i) {
        if (amemory[i] == p) {
            return check_illegal_memory_write(p, amem_size[i]);
        }
    }
    std::cout << "check_illegal_memory_write: " << static_cast<void*>(p)
              << " was not allocated" << std::endl;
    return true;
}

static void free_memory(void* buf) {
    char* p = static_cast<char*>(buf) - LEFT_REDZONE_SIZE;
#ifdef MEM_VERBOSE
    std::cout << "free_memory: " << static_cast<void*>(p) << std::endl;
#endif
    free(static_cast<void*>(p));
}

/* allocate memory and store reference in observation area [sa]memory:
 * - for both single and array allocations
 * - but only if we are in a unit test and have not suspending memchecking
 * - check during delete whether that was correct
 */
void* operator new(std::size_t s) {
    if (s == 0) {
        std::cout << "warning: new of size 0" << std::endl;
        throw std::bad_alloc();
    }
    if (!we_are_testing) {
        return malloc(s);
    }
    size_t current = scurrent_alloc++;
    smemory[current] = allocate_memory(s);
    smem_size[current] = s;
    void* ret = smemory[current];
#ifdef MEM_VERBOSE
    std::cout << std::setw(4) << current << ": ";
    std::cout << "new:      size=" << std::setw(4) << s;
    std::cout << " p=" << ret << std::endl;
#endif
    return ret;
}

void* operator new[](std::size_t s) {
    if (s == 0) {
        std::cout << "warning: new[] of size 0" << std::endl;
        throw std::bad_alloc();
    }
    if (!we_are_testing) {
        return malloc(s);
    }
    size_t current = acurrent_alloc++;
    amemory[current] = allocate_memory(s);
    amem_size[current] = s;
    void* ret = amemory[current];
#ifdef MEM_VERBOSE
    std::cout << std::setw(4) << current << ": ";
    std::cout << "new[]:    size=" << std::setw(4) << s;
    std::cout << " p=" << ret << std::endl;
#endif
    return ret;
}

/* free memory and check whether it has been freed once only in the
 * observation area, if we are in a unit test */
void operator delete(void* p) noexcept {
    if (p == nullptr) { // that is always ok, per C++ spec no effect
        return;
    }
    if (!we_are_testing) { // if not memchecking or memchecking suspended
        free(p); // plain free for plain malloc
        return;
    }
    // try to (linearily) find counterpart during allocation,
    // run through all allocation slots
    const size_t current = scurrent_alloc;
    for (size_t i = 0; i < current; ++i) {
        if (smemory[i] != p) {
            continue;
        }
        // found the slot
        if (smem_freed[i]) { // already deleted
            sdouble_freed.push_back(static_cast<int>(i));
            double_freed += 1;
        } else {
            // do not check for illegal memory write here,
            // as this would register a failure in normal execution...
            // -> do it manually in the test
            // check_illegal_memory_write(p, smem_size[i]);
        }
#ifdef MEM_VERBOSE
        std::cout << std::setw(4) << i << ": ";
        std::cout << "delete:   size=" << std::setw(4) << smem_size[i];
        std::cout << " p=" << p << std::endl;
#endif
        // free(p); // WE DO NOT FREE! -> avoid reuse for analysis
        smem_freed[i] = true;
        scurrent_freed += 1;
        return;
    }
    // found a memory error: this address has not been allocated but freed
    sfreed_notalloc.push_back(p);
    freed_not_allocated += 1;
}

// void the warning
void operator delete(void* p, size_t) noexcept {
    operator delete(p); // just ignore the size
}

void operator delete[](void* p) noexcept {
    if (p == nullptr) { // that is always ok, per C++ spec no effect
        return;
    }
    if (!we_are_testing) {
        free(p);
        return;
    }
    const size_t current = acurrent_alloc;
    for (size_t i = 0; i < current; ++i) {
        if (amemory[i] != p) {
            continue;
        }
        // found the slot
        if (amem_freed[i]) {
            // Note, that we *must not* produce a failure here,
            // as a failure allocates memory, which in turn will
            // get reported. That is why we have a capacity reserved
            // for the errors in the first place.
            adouble_freed.push_back(static_cast<int>(i));
            double_freed += 1;
        } else {
            // do not check for illegal memory write here,
            // as this would register a failure in normal execution...
            // -> do it manually in the test
            // check_illegal_memory_write(p, amem_size[i]);
        }
#ifdef MEM_VERBOSE
        std::cout << std::setw(4) << i << ": ";
        std::cout << "delete[]: size=" << std::setw(4) << amem_size[i];
        std::cout << " p=" << p << std::endl;
#endif
        // free(p); // WE DO NOT FREE! -> avoid reuse
        amem_freed[i] = true;
        acurrent_freed += 1;
        return;
    }
    afreed_notalloc.push_back(p);
    freed_not_allocated += 1;
}

// avoid the warning
void operator delete[](void* p, size_t) noexcept {
    operator delete[](p); // ignore the size;
}

/* At the end of each test we go through the memory and check for errors.
 * We only check allocations that have been allocated during the test.
 * Make sure, that the special new/delete's are off during check_memory.
 * In addition we remove all pointers to allocated but not yet freed memory
 * during the test to let tools like valgrind take their chance.
 */
void check_memory(size_t scall, size_t acall) { // params, where to start
    // std::cout << "check_memory" << std::endl;
    int not_freed = 0;
    int freed = 0;
    // count
    const size_t scurrent = scurrent_alloc;
    for (size_t i = scall; i < scurrent; ++i) {
        if (smem_freed[i]) {
            freed += 1;
        } else {
            not_freed += 1;
            ADD_FAILURE() << " leak=" << smemory[i] << " size=" << smem_size[i];
        }
    }
    const size_t acurrent = acurrent_alloc;
    for (size_t i = acall; i < acurrent; ++i) {
        if (amem_freed[i]) {
            freed += 1;
        } else {
            not_freed += 1;
            ADD_FAILURE() << " leak[]=" << amemory[i]
                          << " size=" << amem_size[i];
        }
    }
    for (const int idx : sdouble_freed) {
        ADD_FAILURE() << " double_free=" << smemory[idx]
                      << " size=" << smem_size[idx];
    }
    for (const int idx : adouble_freed) {
        ADD_FAILURE() << " double_free[]=" << amemory[idx]
                      << " size=" << amem_size[idx];
    }
    for (void* p : sfreed_notalloc) {
        ADD_FAILURE() << " freed_not_alloc=" << p;
    }
    for (void* p : afreed_notalloc) {
        ADD_FAILURE() << " freed_not_alloc[]=" << p;
    }
    bool error = false;
    const int allocs =
        static_cast<int>((scurrent - scall) + (acurrent - acall));
    if (allocs != freed) {
        if (error == false) {
            std::cout << "Speicherprüfung:";
        }
        error = true;
        ADD_FAILURE() << " allokiert=" << allocs << " freigegeben=" << freed
                      << " leak=" << (allocs - freed);
    }
    if (double_freed > 0) {
        if (error == false) {
            std::cout << "Speicherprüfung:";
        }
        error = true;
        ADD_FAILURE() << " double_freed=" << double_freed;
    }
    if (freed_not_allocated > 0) {
        if (error == false) {
            std::cout << "Speicherprüfung:";
        }
        error = true;
        ADD_FAILURE() << " freed_not_allocated=" << freed_not_allocated;
    }
    if (not_freed > 0) {
        if (error == false) {
            std::cout << "Speicherprüfung:";
        }
        error = true;
        ADD_FAILURE() << " allocated_not_freed=" << freed_not_allocated;
    }
    if (error == true) {
        std::cout << std::endl;
    }
    // if (errors == 0) {
    //     std::cout << "Keine Speicherfehler, alles gut" << std::endl;
    // } else {
    //     std::cout << "Speicherfehler: " << errors << std::endl;
    // }
    // Here, we can try to free...
    for (size_t i = scall; i < scurrent; ++i) {
        if (smem_freed[i]) {
            free_memory(smemory[i]);
        } // // keep the leaks (for valgrind)
        smemory[i] = nullptr; // but not a reference to the leaked area
    }
    for (size_t i = acall; i < acurrent; ++i) {
        if (amem_freed[i]) {
            free_memory(amemory[i]);
        }
        amemory[i] = nullptr;
    }
    // reset global ones already reported
    double_freed = 0;
    freed_not_allocated = 0;
}
