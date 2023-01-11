//
// Created by Bobbyshu on 2023/1/10.
//
#include<iostream>
#include<unordered_map>

//using namespace std;

int hash_map() {
    //定义容器
    std::unordered_map<std::string, int> my_map;

    //插入键值对
    my_map["apple"] = 10;
    my_map["banana"] = 20;

    //获取头部的迭代器，以及尾部再向下一的迭代器
    for (auto iter = my_map.begin(); iter != my_map.end(); iter++) {
        std::cout << iter->first << " :" << iter->second << std::endl;
    }

    //若容器为空则为 1 ，否则为 0
    std::cout << my_map.empty() << std::endl;

    //寻找键等于 key 的的元素。
    auto search = my_map.find("apple");
    std::cout << search->second << std::endl;

    //返回拥有比较等于指定参数 key 的关键的元素数，因为此容器不允许重复故为 1 或 0 。
    std::cout << my_map.count("apple") << std::endl;

    return 0;

}
