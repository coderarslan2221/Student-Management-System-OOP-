#include "Student.h"
#include <stdexcept>

int Student::totalStudents = 0;

Student::Student() : Person()
{
    department = "None";
    cgpa = 0.0;

    totalStudents++;
}

Student::Student(int i, string n, string d, float c)
    : Person(i, n)
{
    department = d;

    if(c < 0 || c > 4.0)
    {
        throw invalid_argument("CGPA must be between 0 and 4");
    }

    cgpa = c;

    totalStudents++;
}

void Student::setDepartment(string d)
{
    department = d;
}

void Student::setCGPA(float c)
{
    if(c < 0 || c > 4.0)
    {
        throw invalid_argument("Invalid CGPA");
    }

    cgpa = c;
}

string Student::getDepartment()
{
    return department;
}

float Student::getCGPA()
{
    return cgpa;
}

void Student::display()
{
    cout << "ID: " << id << endl;
    cout << "Name: " << name << endl;
    cout << "Department: " << department << endl;
    cout << "CGPA: " << cgpa << endl;
}

bool Student::operator==(Student &s)
{
    if(id == s.id)
    {
        return true;
    }

    return false;
}

ostream& operator<<(ostream &out, Student &s)
{
    out << s.id << " "
        << s.name << " "
        << s.department << " "
        << s.cgpa;

    return out;
}