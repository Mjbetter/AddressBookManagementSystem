#include "function.h"

#define MAXSIZE 1000

/*Add new person to the address book*/
void add_person(struct Person* p,int *count) {
	if (*count >= MAXSIZE) {
		cout << "通讯录已满,无法添加" << endl;
		system("pause");
		return;
	}
	cout << "请输入姓名:";
	cin >> p[*count].name;
	cout << endl;
	cout << "请输入性别:(男或女)";
	while (cin >> p[*count].sex) {
		if (p[*count].sex == "男" || p[*count].sex == "女") {
			break;
		}
		else {
			cout << "请输入正确的性别：（男或女）" << endl;
		}
	}
	cout << endl;
	cout << "请输入年龄:（0-110）";
	while (cin >> p[*count].age) {
		if (p[*count].age >= 0 && p[*count].age <= 110) {
			break;
		}
		else {
			cout << "请输入正确的年龄：（0-110）" << endl;
		}
	}
	cout << endl;
	cout << "请输入联系电话:";
	cin >> p[*count].phone_number;
	cout << endl;
	cout << "请输入家庭住址:";
	cin >> p[(*count)++].address;
	cout << endl;
	cout << endl << endl << "添加成功，即将返回主菜单...";
	system("pause");
}

/*show all person of the address book*/
void show_person(const struct Person* p,int count) {
	if (count == 0) {
		cout << "您的通讯录中暂无信息，请添加信息" << endl;
		system("pause");
		return;
	}
	cout << "您的通讯录中有如下亲朋好友：" << endl;
	cout << left << setw(8) << "姓名" << setw(8) << "性别" << setw(8) << "年龄" << setw(26) << "联系电话" << setw(40) << "家庭住址" << endl;
	for (int i = 0; i < count; i++) {
		/*aligned to the left*/
		cout << left << setw(8) << p[i].name << setw(8) << p[i].sex << setw(8) << p[i].age << setw(26) << p[i].phone_number << setw(40) << p[i].address << endl;
	}
	system("pause");
}

/*delete specified person of the address book*/
void delete_person(struct Person* p,string name,int *count) {
	int judge = 0;
	for (int i = 0; i < *count; i++) {
		if (p[i].name == name) {
			judge = 1;
			for (int j = i; j < (*count)-1; j++) {
				p[j] = p[j + 1];
			}
			*count = *count - 1;
		}
	}
	if (judge == 0) cout << "对不起，你的通讯录中不存在此人" << endl;
	else cout << "已经删除所有名字为" << name << "的联系人";
	system("pause");
}

/*find specified person of the address book*/
void find_person(const struct Person* p,string name,int count) {
	for (int i = 0; i < count; i++) {
		if (p[i].name == name) {
			cout << left << setw(8) << "姓名" << setw(8) << "性别" << setw(8) << "年龄" << setw(8) << "联系电话" << setw(8) << "家庭住址" << endl;
			cout << left << setw(8) << p[i].name << setw(8) << p[i].sex << setw(8) << p[i].age << setw(8) << p[i].phone_number << setw(8) << p[i].address << endl;
			break;
		}
	}
	system("pause");
}

/*modify specified person of the address book*/
void modify_person(struct Person* p,string name,int count) {
	for (int i = 0; i < count; i++) {
		if (p[i].name == name) {
			cout << "请输入姓名:";
			cin >> p[i].name;
			cout << endl;
			cout << "请输入性别:";
			cin >> p[i].sex;
			cout << endl;
			cout << "请输入年龄:";
			cin >> p[i].age;
			cout << endl;
			cout << "请输入联系电话:";
			cin >> p[i].phone_number;
			cout << endl;
			cout << "请输入家庭住址:";
			cin >> p[i].address;
			cout << endl;
			cout << endl << endl << "修改成功，即将返回主菜单...";
			Sleep(3000);
			break;
		}
	}
}

/*clean all person of the address book*/
void clean_person(struct Person* p,int *counts) {
	for (int i = 0; i < *counts; i++) {
		memset(&p[i], '\0', sizeof(struct Person));
	}
	cout << "已经清空所有联系人" << endl;
	*counts = 0;
	system("pause");
}