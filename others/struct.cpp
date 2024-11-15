//
// Created by Bobbyshu on 2022/12/17.
//

#include <iostream>
using namespace std;

struct Student {
    string name;
    int age;
    int score;

};

int test() {
    struct Student s1;
    s1.age = 23;
    s1.name = "shuyunmu";
    s1.score = 100;

    cout << s1.name << endl;

    struct Student s2 = {"Bobby", 20, 95};
}
