using namespace std;

template <typename T>
class Sequence {
public:
    Sequence(size_t cap);
    Sequence(const Sequence&);
    Sequence& operator=(const Sequence&);
    ~Sequence();
    size_t size() const;
    size_t capacity() const;
    bool is_empty() const;
    bool is_full() const;
    T& operator[](size_t pos);
    const T& operator[](size_t pos) const;
    void insert(size_t pos, const T& ele);
    void push_back(const T& ele);
    void remove(size_t pos);
    bool remove_ele(const T& ele);

private:
    T* _array;
    size_t _cap;
    size_t _size;
};