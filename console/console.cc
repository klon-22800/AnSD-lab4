#include<iostream>
#include<set/set.h>

using namespace std;
using namespace set;


int main(){
    Set<int> a;
    a.insert(1);
    a.insert(3);
    Set<int> b;
    b.insert(1);
    b.insert(2);
    Set<int> d;
    a.print();
    b.print();
    d.print();

}