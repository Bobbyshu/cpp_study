//
// Created by Bobbyshu on 2022/12/15.
//
#include <iostream>

//using namespace std;

int pointer() {
    //null pointer
    int a = 10;
//    int* p = NULL;
    std::cout << "hello" << std::endl;
//    *p = 100;
    std::cout << "hello" << std::endl;
    //wild pointer
    int *p = (int *) 0x1100;
    std::cout << "hello" << std::endl;
    std::cout << *p << std::endl;
    system("pause");
    return 0;

//    int a = 10;
//    int b = 10;
//     const 修饰常量，就叫常量指针can only change orientation but can't change value
//     const int *p = &a;
//     const 修饰指针，就叫指针常量can only change value but can't change orientation
//     int * const p = &a;
     // const 全部都修饰，两个都不能改
//     const int * const p = &a;
     //change location
     *p = 20; //wrong cuz const can only change orientation but can't change value
     //change value
     p = &b;
}
