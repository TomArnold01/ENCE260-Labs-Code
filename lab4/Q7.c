#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct {
    uint64_t ID;
    uint8_t age;
    float GPA;
} Student_t;

Student_t newStudent(uint64_t id, uint8_t age, float gpa) 
{
    Student_t v;
    v.ID = id;
    v.age = age;
    v.GPA = gpa;
    return v;
}

void printStudent(const Student_t* student) 
{
    printf("%lu: Age %d, GPA %.2f\n", student->ID, student->age, student->GPA);
}

void updateGpa(Student_t* student, float newGpa)
{
    (*student).GPA = newGpa;
}

int main(void) 
{
	
Student_t students[3];
students[0] = newStudent(12345678, 19, 5.62);
students[1] = newStudent(90817263, 2, 0); //A bit young for university
students[2] = newStudent(56456444, 20, 7.5);
for (size_t i = 0; i < 3; i++) {
    printStudent(&students[i]);
}
}