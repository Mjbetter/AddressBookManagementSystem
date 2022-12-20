#include <iostream>
#include <string>
#include <Windows.h>
#include "show_menu.h"
#include "function.h"
#include "structure.h"
#include<stdlib.h>

using namespace std;


struct Person persons[1000];
int counts;


int main() {

	while (1) {
		int number = main_menu();
		string name;
		//according to the serial number to jump interface
		switch (number)
		{
		case 1:
			system("cls");
			add_person(persons, &counts);
			break;
		case 2:
			system("cls");
			show_person(persons, counts);
			break;
		case 3:
			cout << "请输入想要删除的联系人的姓名:" << endl;
			cin >> name;
			delete_person(persons, name, &counts);
			break;
		case 4:
			cout << "请输入想要查找的联系人的姓名:" << endl;
			cin >> name;
			find_person(persons, name, counts);
			break;
		case 5:
			cout << "请输入想要修改的联系人的姓名:" << endl;
			cin >> name;
			modify_person(persons, name, counts);
			break;
		case 6:
			clean_person(persons, &counts);
			break;
		case 7:
			cout << "3秒后退出系统";
			Sleep(3000);
			exit(0);
			break;
		}
	}
}