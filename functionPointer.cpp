//
// Created by Bobbyshu on 2022/12/17.
//

#include <iostream>

using namespace std;

void swap(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int test() {
    int a = 10, b = 20;
    cout << "before a = " << a << endl;
    cout << "before b = " << b << endl;
    swap(&a, &b);
    cout << "after a = " << a << endl;
    cout << "after b = " << b << endl;
}