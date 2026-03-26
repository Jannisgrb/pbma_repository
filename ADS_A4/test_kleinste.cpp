#include "alltest.h"
#include "kleinste.h"
#include <climits>

using namespace std;

TEST(kleinste, a) {
    vector<int> a1 = {1, 2, 3, 4};
    int k1 = kleinste(a1);
    EXPECT_EQ(k1, 1);
    vector<int> a2 = {4, 2, 5, 3};
    int k2 = kleinste(a2);
    EXPECT_EQ(k2, 2);
    vector<int> a3 = {4, -2, 5, -3, 17};
    int k3 = kleinste(a3);
    EXPECT_EQ(k3, -3);
}

TEST(kleinste, b) {
    vector<int> empty;
    int k1 = kleinste(empty);
    EXPECT_EQ(k1, INT_MAX);
    vector<int> b = {-1000000};
    int k2 = kleinste(b);
    EXPECT_EQ(k2, b[0]);
}
