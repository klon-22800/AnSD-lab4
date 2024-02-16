#include <gtest/gtest.h>
#include <set/set.h>
using namespace std;
using namespace set;

TEST(Functions_test, constuct) {
    Set<int> a;
    a.insert(10);
    a.insert(11);
    a.insert(9);
    a.insert(8);
    a.insert(15);
    a.print();
}
TEST(Functions_test, insert_true) {
    Set<int> a;
    bool b = a.insert(10);
    EXPECT_EQ(b, true);
}
TEST(Functions_test, insert_false) {
    Set<int> a;
    a.insert(10);
    bool b = a.insert(10);
    EXPECT_EQ(b, false);
}
TEST(Functions_test, contains_true) {
    Set<int> a;
    a.insert(10);
    a.insert(11);
    a.insert(9);
    a.insert(8);
    a.insert(15);
    bool b = a.contains(10);
    EXPECT_EQ(b, true);
}
TEST(Functions_test, contains_false) {
    Set<int> a;
    a.insert(10);
    a.insert(11);
    a.insert(9);
    a.insert(8);
    a.insert(15);
    bool b = a.contains(5);
    EXPECT_EQ(b, false);
}
TEST(Functions_test, erase_true) {
    Set<int> a;
    a.insert(10);
    a.insert(11);
    a.insert(9);
    a.insert(8);
    a.insert(15);
    bool b = a.erase(15);
    a.print();
    EXPECT_EQ(b, true);
}
TEST(Functions_test, erase_false) {
    Set<int> a;
    a.insert(10);
    a.insert(11);
    a.insert(9);
    a.insert(8);
    a.insert(15);
    bool b = a.erase(1);
    a.print();
    EXPECT_EQ(b, false);
}
TEST(Functions_test, string_set) {
    Set<string> a;
    a.insert("Mother");
    a.insert("Father");
    a.insert("Sister");
    a.insert("Me");
    a.print();
    bool b = a.contains("Me");
    a.erase("Me");
    a.print();
    EXPECT_EQ(b, true);
}
