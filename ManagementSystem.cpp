//
// Created by Bobbyshu on 2022/12/17.
//

#include <iostream>

using namespace std;
#define MAX 1000

struct Person {
    string m_Name;
    // 1 for male 2 for female
    int m_Sex;
    int m_Age;
    string m_Phone;
    string m_Addr;
};

struct AddressBooks {
    Person personArray[MAX];
    int m_Size;
};

void addPerson(AddressBooks *abs) {
    if (abs->m_Size == MAX) {
        cout << "通讯录已满，无法添加！ " << endl;
        return;
    }
    //name
    string name;
    cout << "请输入姓名：" << endl;
    cin >> name;
    abs->personArray[abs->m_Size].m_Name = name;

    //gender
    cout << "请输入性别：" << endl;
    cout << "1 --- 男" << endl;
    cout << "2 --- 女" << endl;
    int sex = 0;
    while (true) {
        //only valid input will quit the loop
        cin >> sex;
        if (sex == 1 || sex == 2) {
            abs->personArray[abs->m_Size].m_Sex = sex;
            break;
        }
        cout << "输入有误，请重新输入" << endl;
    }

    //age
    cout << "请输入年龄：" << endl;
    int age = 0;
    cin >> age;
    abs->personArray[abs->m_Size].m_Age = age;

    //phone number
    cout << "请输入联系电话：" << endl;
    string phone;
    cin >> phone;
    abs->personArray[abs->m_Size].m_Phone = phone;

    //address
    cout << "请输入家庭住址：" << endl;
    string address;
    cin >> address;
    abs->personArray[abs->m_Size].m_Addr = address;

    abs->m_Size++;

    cout << "添加成功！" << endl;
    system("cls");

}

void showPerson(AddressBooks *abs) {
    if (abs->m_Size == 0) {
        cout << "当前记录为空" << endl;
    } else {
        for (int i = 0; i < abs->m_Size; ++i) {
            cout << "姓名： " << abs->personArray[i].m_Name << "\t";
            cout << "性别： " << (abs->personArray[i].m_Sex == 1 ? "男" : "女") << "\t";
            cout << "年龄： " << abs->personArray[i].m_Age << "\t";
            cout << "电话： " << abs->personArray[i].m_Phone << "\t";
            cout << "住址： " << abs->personArray[i].m_Addr << endl;
        }
    }

    system("pause");
    system("cls");
}

int isExist(AddressBooks *abs, string name) {
    for (int i = 0; i < abs->m_Size; ++i) {
        if (abs->personArray[i].m_Name == name) {
            return i;
        }
    }
    return -1;
}

void deletePerson(AddressBooks *abs) {
    cout << "请输入你要删除的联系人" << endl;
    string name;
    cin >> name;

    int res = isExist(abs, name);

    if (res != -1) {
        for (int i = res; i < abs->m_Size; ++i) {
            abs->personArray[i] = abs->personArray[i + 1];
        }
        abs->m_Size--;
        cout << "删除成功" << endl;
    } else {
        cout << "查无此人" << endl;
    }

    system("pause");
    system("cls");
}

void searchPerson(AddressBooks *abs) {
    cout << "请输入要查找的联系人" << endl;
    string name;
    cin >> name;

    int res = isExist(abs, name);
    if (res != -1) {
        cout << "姓名： " << abs->personArray[res].m_Name << "\t";
        cout << "性别： " << (abs->personArray[res].m_Sex == 1 ? "男" : "女") << "\t";
        cout << "年龄： " << abs->personArray[res].m_Age << "\t";
        cout << "电话： " << abs->personArray[res].m_Phone << "\t";
        cout << "住址： " << abs->personArray[res].m_Addr << endl;
    } else {
        cout << "查无此人" << endl;
    }

    system("pause");
    system("cls");
}

void modifyPerson(AddressBooks *abs) {
    cout << "请输入要修改的联系人" << endl;
    string name;
    cin >> name;

    int res = isExist(abs, name);
    if (res != -1) {
        string name;
        cout << "请输入姓名" << endl;
        cin >> name;
        abs->personArray[res].m_Name = name;

        cout << "请输入性别" << endl;
        cout << "1 --- 男" << endl;
        cout << "2 --- 女" << endl;
        int sex = 0;

        while (true) {
            cin >> sex;
            if (sex == 1 || sex == 2) {
                abs->personArray[res].m_Sex = sex;
                break;
            }
            cout << "输入有误，请重新输入" << endl;
        }

        cout << "请输入年龄" << endl;
        int age = 0;
        cin >> age;
        abs->personArray[res].m_Age = age;

        cout << "请输入联系电话" << endl;
        string phone;
        cin >> phone;
        abs->personArray[res].m_Phone = phone;

        cout << "请输入家庭住址" << endl;
        string address;
        cin >> address;
        abs->personArray[res].m_Addr = address;

        cout << "修改成功" << endl;

    } else {
        cout << "查无此人" << endl;
    }

    system("pause");
    system("cls");
}

void cleanPerson(AddressBooks *abs) {
    abs->m_Size = 0;
    cout << "删库跑路" << endl;
    system("pause");
    system("cls");
}

void showMenu() {
    cout << "***********************" << endl;
    cout << "***** 1. 添加联系人 *****" << endl;
    cout << "***** 2. 显示联系人 *****" << endl;
    cout << "***** 3. 删除联系人 *****" << endl;
    cout << "***** 4. 查找联系人 *****" << endl;
    cout << "***** 5. 修改联系人 *****" << endl;
    cout << "***** 6. 清空联系人 *****" << endl;
    cout << "***** 0. 退出通讯录 *****" << endl;
    cout << "***********************" << endl;
}

int main() {
    AddressBooks abs;
    abs.m_Size = 0;

    int select = 0;

    while (true) {
        showMenu();

        cin >> select;

        switch (select) {
            case 1:
                addPerson(&abs);
                break;
            case 2:
                showPerson(&abs);
                break;
            case 3:
//            {
//                cout << "请输入删除联系人姓名： " << endl;
//                string name;
//                cin >> name;
//                if (isExist(&abs, name) == -1) {
//                    cout << "查无此人" << endl;
//                } else {
//                    cout << "找到此人" << endl;
//                }
//                break;
//            }
                deletePerson(&abs);
                break;
            case 4:
                searchPerson(&abs);
                break;
            case 5:
                modifyPerson(&abs);
                break;
            case 6:
                cleanPerson(&abs);
                break;
            case 0:
                cout << "欢迎下次使用" << endl;
                system("pause");
                return 0;
            default:
                break;
        }
    }

    system("pause");
    return 0;
}
