#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
	char *name;
	int age;
	double height;
} Person_t;

Person_t* newPerson(const char *name, int age, double height) {

	//create a person_t pointer t in heap
	Person_t *ptr = (Person_t *)calloc(1, sizeof(Person_t));

	//create a char pointer whose size is size of const char * name
	char *nname = calloc(1, sizeof(name));

	//copy the string by strcpy function
	strcpy(nname, name);

	//assign the value of attribute
	ptr->name = nname;
	ptr->age = age;
	ptr->height = height;

	return ptr;
}

void freePerson(Person_t* person) {

	//first free the name
	free(person->name) ;

	//then free the employee
	free(person);
}

int main() 
{
    Person_t* employee = newPerson("Billy", 30, 1.68);
    printf("%s is age %d and is %.2f m tall\n", employee->name, employee->age, employee->height);
    freePerson(employee);  

}