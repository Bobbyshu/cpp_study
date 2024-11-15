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
        cout << "ͨѶ¼�������޷����ӣ� " << endl;
        return;
    }
    //name
    string name;
    cout << "������������" << endl;
    cin >> name;
    abs->personArray[abs->m_Size].m_Name = name;

    //gender
    cout << "�������Ա�" << endl;
    cout << "1 --- ��" << endl;
    cout << "2 --- Ů" << endl;
    int sex = 0;
    while (true) {
        //only valid input will quit the loop
        cin >> sex;
        if (sex == 1 || sex == 2) {
            abs->personArray[abs->m_Size].m_Sex = sex;
            break;
        }
        cout << "������������������" << endl;
    }

    //age
    cout << "���������䣺" << endl;
    int age = 0;
    cin >> age;
    abs->personArray[abs->m_Size].m_Age = age;

    //phone number
    cout << "��������ϵ�绰��" << endl;
    string phone;
    cin >> phone;
    abs->personArray[abs->m_Size].m_Phone = phone;

    //address
    cout << "�������ͥסַ��" << endl;
    string address;
    cin >> address;
    abs->personArray[abs->m_Size].m_Addr = address;

    abs->m_Size++;

    cout << "���ӳɹ���" << endl;
    system("cls");

}

void showPerson(AddressBooks *abs) {
    if (abs->m_Size == 0) {
        cout << "��ǰ��¼Ϊ��" << endl;
    } else {
        for (int i = 0; i < abs->m_Size; ++i) {
            cout << "������ " << abs->personArray[i].m_Name << "\t";
            cout << "�Ա� " << (abs->personArray[i].m_Sex == 1 ? "��" : "Ů") << "\t";
            cout << "���䣺 " << abs->personArray[i].m_Age << "\t";
            cout << "�绰�� " << abs->personArray[i].m_Phone << "\t";
            cout << "סַ�� " << abs->personArray[i].m_Addr << endl;
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
    cout << "��������Ҫɾ������ϵ��" << endl;
    string name;
    cin >> name;

    int res = isExist(abs, name);

    if (res != -1) {
        for (int i = res; i < abs->m_Size; ++i) {
            abs->personArray[i] = abs->personArray[i + 1];
        }
        abs->m_Size--;
        cout << "ɾ���ɹ�" << endl;
    } else {
        cout << "���޴���" << endl;
    }

    system("pause");
    system("cls");
}

void searchPerson(AddressBooks *abs) {
    cout << "������Ҫ���ҵ���ϵ��" << endl;
    string name;
    cin >> name;

    int res = isExist(abs, name);
    if (res != -1) {
        cout << "������ " << abs->personArray[res].m_Name << "\t";
        cout << "�Ա� " << (abs->personArray[res].m_Sex == 1 ? "��" : "Ů") << "\t";
        cout << "���䣺 " << abs->personArray[res].m_Age << "\t";
        cout << "�绰�� " << abs->personArray[res].m_Phone << "\t";
        cout << "סַ�� " << abs->personArray[res].m_Addr << endl;
    } else {
        cout << "���޴���" << endl;
    }

    system("pause");
    system("cls");
}

void modifyPerson(AddressBooks *abs) {
    cout << "������Ҫ�޸ĵ���ϵ��" << endl;
    string name;
    cin >> name;

    int res = isExist(abs, name);
    if (res != -1) {
        string name;
        cout << "����������" << endl;
        cin >> name;
        abs->personArray[res].m_Name = name;

        cout << "�������Ա�" << endl;
        cout << "1 --- ��" << endl;
        cout << "2 --- Ů" << endl;
        int sex = 0;

        while (true) {
            cin >> sex;
            if (sex == 1 || sex == 2) {
                abs->personArray[res].m_Sex = sex;
                break;
            }
            cout << "������������������" << endl;
        }

        cout << "����������" << endl;
        int age = 0;
        cin >> age;
        abs->personArray[res].m_Age = age;

        cout << "��������ϵ�绰" << endl;
        string phone;
        cin >> phone;
        abs->personArray[res].m_Phone = phone;

        cout << "�������ͥסַ" << endl;
        string address;
        cin >> address;
        abs->personArray[res].m_Addr = address;

        cout << "�޸ĳɹ�" << endl;

    } else {
        cout << "���޴���" << endl;
    }

    system("pause");
    system("cls");
}

void cleanPerson(AddressBooks *abs) {
    abs->m_Size = 0;
    cout << "ɾ����·" << endl;
    system("pause");
    system("cls");
}

void showMenu() {
    cout << "***********************" << endl;
    cout << "***** 1. ������ϵ�� *****" << endl;
    cout << "***** 2. ��ʾ��ϵ�� *****" << endl;
    cout << "***** 3. ɾ����ϵ�� *****" << endl;
    cout << "***** 4. ������ϵ�� *****" << endl;
    cout << "***** 5. �޸���ϵ�� *****" << endl;
    cout << "***** 6. �����ϵ�� *****" << endl;
    cout << "***** 0. �˳�ͨѶ¼ *****" << endl;
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
//                cout << "������ɾ����ϵ�������� " << endl;
//                string name;
//                cin >> name;
//                if (isExist(&abs, name) == -1) {
//                    cout << "���޴���" << endl;
//                } else {
//                    cout << "�ҵ�����" << endl;
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
                cout << "��ӭ�´�ʹ��" << endl;
                system("pause");
                return 0;
            default:
                break;
        }
    }

    system("pause");
    return 0;
}