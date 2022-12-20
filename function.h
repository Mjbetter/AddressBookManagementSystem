#include <iostream>
#include <string>
#include <Windows.h>
#include <iomanip>
#include "structure.h"

using namespace std;


/*Add new person to the address book*/
void add_person(struct Person *p,int *count);

/*show all person of the address book*/
void show_person(const struct Person* p,int count);

/*delete specified person of the address book*/
void delete_person(struct Person* p,string name,int *count);

/*find specified person of the address book*/
void find_person(const struct Person* p,string name,int count);

/*modify specified person of the address book*/
void modify_person(struct Person* p,string name,int count);

/*clean all person of the address book*/
void clean_person(struct Person* p,int *counts);
