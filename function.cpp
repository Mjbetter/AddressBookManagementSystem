#include "function.h"

#define MAXSIZE 1000

/*Add new person to the address book*/
void add_person(struct Person* p,int *count) {
	if (*count >= MAXSIZE) {
		cout << "ͨѶ¼����,�޷����" << endl;
		system("pause");
		return;
	}
	cout << "����������:";
	cin >> p[*count].name;
	cout << endl;
	cout << "�������Ա�:(�л�Ů)";
	while (cin >> p[*count].sex) {
		if (p[*count].sex == "��" || p[*count].sex == "Ů") {
			break;
		}
		else {
			cout << "��������ȷ���Ա𣺣��л�Ů��" << endl;
		}
	}
	cout << endl;
	cout << "����������:��0-110��";
	while (cin >> p[*count].age) {
		if (p[*count].age >= 0 && p[*count].age <= 110) {
			break;
		}
		else {
			cout << "��������ȷ�����䣺��0-110��" << endl;
		}
	}
	cout << endl;
	cout << "��������ϵ�绰:";
	cin >> p[*count].phone_number;
	cout << endl;
	cout << "�������ͥסַ:";
	cin >> p[(*count)++].address;
	cout << endl;
	cout << endl << endl << "��ӳɹ��������������˵�...";
	system("pause");
}

/*show all person of the address book*/
void show_person(const struct Person* p,int count) {
	if (count == 0) {
		cout << "����ͨѶ¼��������Ϣ���������Ϣ" << endl;
		system("pause");
		return;
	}
	cout << "����ͨѶ¼��������������ѣ�" << endl;
	cout << left << setw(8) << "����" << setw(8) << "�Ա�" << setw(8) << "����" << setw(26) << "��ϵ�绰" << setw(40) << "��ͥסַ" << endl;
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
	if (judge == 0) cout << "�Բ������ͨѶ¼�в����ڴ���" << endl;
	else cout << "�Ѿ�ɾ����������Ϊ" << name << "����ϵ��";
	system("pause");
}

/*find specified person of the address book*/
void find_person(const struct Person* p,string name,int count) {
	for (int i = 0; i < count; i++) {
		if (p[i].name == name) {
			cout << left << setw(8) << "����" << setw(8) << "�Ա�" << setw(8) << "����" << setw(8) << "��ϵ�绰" << setw(8) << "��ͥסַ" << endl;
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
			cout << "����������:";
			cin >> p[i].name;
			cout << endl;
			cout << "�������Ա�:";
			cin >> p[i].sex;
			cout << endl;
			cout << "����������:";
			cin >> p[i].age;
			cout << endl;
			cout << "��������ϵ�绰:";
			cin >> p[i].phone_number;
			cout << endl;
			cout << "�������ͥסַ:";
			cin >> p[i].address;
			cout << endl;
			cout << endl << endl << "�޸ĳɹ��������������˵�...";
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
	cout << "�Ѿ����������ϵ��" << endl;
	*counts = 0;
	system("pause");
}