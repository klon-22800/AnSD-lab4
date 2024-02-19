#include <gtest/gtest.h>
#include <set/set.h>
#include<set/set_copy.h>
using namespace std;
using namespace set;
using namespace set_c;

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
//TEST(Functions_test, fill_time_test) {
//    cout << "Fill 1000 - " << fill_time(1000, 100) << endl;
//    cout << "Fill 10000 - " << fill_time(10000, 100) << endl;
//    cout << "Fill 100000 - " << fill_time(100000, 100) << endl;
//}
//TEST(Functions_test, contain_time_test) {
//    cout << "Contain 1000 - " << contain_time(1000, 1000) << endl;
//    cout << "Contain 10000 - " << contain_time(10000, 1000) << endl;
//    cout << "Contain 100000 - " << contain_time(100000, 1000) << endl;
//}
//TEST(Functions_test, insert_time_test) {
//    cout << "Insert 1000 - " << insert_time(1000, 1000) << endl;
//    cout << "Insert 10000 - " << insert_time(10000, 1000) << endl;
//    cout << "Insert 100000 - " << insert_time(100000, 1000) << endl;
//}
//TEST(Functions_test, erase_time_test) {
//    cout << "Erase 1000 - " << insert_time(1000, 1000) << endl;
//    cout << "Erase 10000 - " << insert_time(10000, 1000) << endl;
//    cout << "Erase 100000 - " << insert_time(100000, 1000) << endl;
//}
//TEST(Functions_test, fill_time_test_vect) {
//    cout << "Fill_vect 1000 - " << fill_time_vect(1000, 100) << endl;
//    cout << "Fill_vect 10000 - " << fill_time_vect(10000, 100) << endl;
//    cout << "Fill_vect 100000 - " << fill_time_vect(100000, 100) << endl;
//}
//TEST(Functions_test, contain_time_test_vect) {
//    cout << "Contain_vect 1000 - " << contain_time_vect(1000, 1000) << endl;
//    cout << "Contain_vect 10000 - " << contain_time_vect(10000, 1000) << endl;
//    cout << "Contain_vect 100000 - " << contain_time_vect(100000, 1000) << endl;
//}
//TEST(Functions_test, insert_time_test_vect) {
//    cout << "Insert_vect 1000 - " << insert_time_vect(1000, 1000) << endl;
//    cout << "Insert_vect 10000 - " << insert_time_vect(10000, 1000) << endl;
//    cout << "Insert_vect 100000 - " << insert_time_vect(100000, 1000) << endl;
//}
//TEST(Functions_test, erase_time_test_vect) {
//    cout << "Erase_vect 1000 - " << insert_time_vect(1000, 1000) << endl;
//    cout << "Erase_vect 10000 - " << insert_time_vect(10000, 1000) << endl;
//    cout << "Erase_vect 100000 - " << insert_time_vect(100000, 1000) << endl;
//}

TEST(Functions_test, set_c_all_test) {
    Set_c<int> a;
    a.insert(10);
    a.insert(11);
    a.insert(9);
    a.insert(8);
    a.insert(8);
    a.insert(15);
    a.erase(8);
    cout<<a.contains(8);
    bool b = a.erase(1);
    a.print();
    EXPECT_EQ(b, false);
}
TEST(Functions_test, set_c_XoR_and_union) {
    Set_c<int> a;
    a.insert(10);
    a.insert(11);
    a.insert(9);
    a.insert(8);
    a.insert(8);
    a.insert(15);
    Set_c<int> b = a;
    b.insert(100);
    b.insert(200);
    set_union(a, b).print();
    XoR(a, b).print();

}
TEST(Functions_test, set_c_count) {
    Set_c<int> a;
    a.insert(10);
    a.insert(11);
    a.insert(9);
    a.insert(8);
    a.insert(8);
    a.insert(15);
    cout << a.count(-100);

}