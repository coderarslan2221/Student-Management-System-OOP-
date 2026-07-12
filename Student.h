#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"
#include <iostream>
#include <string>

using namespace std;

class Student : public Person
{
private:
    string department;
    float cgpa;

public:
    static int totalStudents;

    Student();
    Student(int, string, string, float);

    void setDepartment(string);
    void setCGPA(float);

    string getDepartment();
    float getCGPA();

    void display();

    bool operator==(Student &s);

    friend ostream& operator<<(ostream &out, Student &s);
};

#endif