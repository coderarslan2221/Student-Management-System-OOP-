#include <iostream>
#include <vector>
#include <limits>
//#include <stdexcept>

#include "Student.h"
#include "Course.h"
#include "FileManager.h"

using namespace std;

void addStudent(vector<Student> &students);
void displayStudents(vector<Student> &students);
void searchStudent(vector<Student> &students, int id);
void searchStudent(vector<Student> &students, string name);
void updateStudent(vector<Student> &students);
void deleteStudent(vector<Student> &students);

int main()
{
    vector<Student> students;

    FileManager::loadStudents(students);

    int choice;

    do
    {
        cout << endl;
        cout << "====================================" << endl;
        cout << " STUDENT MANAGEMENT SYSTEM" << endl;
        cout << "====================================" << endl;

        cout << "1. Add Student" << endl;
        cout << "2. Display Students" << endl;
        cout << "3. Search Student By ID" << endl;
        cout << "4. Search Student By Name" << endl;
        cout << "5. Update Student" << endl;
        cout << "6. Delete Student" << endl;
        cout << "7. Save Data" << endl;
        cout << "8. Total Students" << endl;
        cout << "9. Exit" << endl;

        cout << "Enter Choice: ";
        cin >> choice;

        if(cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');

            cout << "Invalid Input" << endl;
            continue;
        }

        if(choice == 1)
        {
            addStudent(students);
        }
        else if(choice == 2)
        {
            displayStudents(students);
        }
        else if(choice == 3)
        {
            int id;

            cout << "Enter ID: ";
            cin >> id;

            searchStudent(students, id);
        }
        else if(choice == 4)
        {
            string name;

            cout << "Enter Name: ";
            cin >> name;

            searchStudent(students, name);
        }
        else if(choice == 5)
        {
            updateStudent(students);
        }
        else if(choice == 6)
        {
            deleteStudent(students);
        }
        else if(choice == 7)
        {
            FileManager::saveStudents(students);

            cout << "Data Saved Successfully" << endl;
        }
        else if(choice == 8)
        {
            cout << "Total Students: "
                 << Student::totalStudents
                 << endl;
        }
        else if(choice == 9)
        {
            FileManager::saveStudents(students);

            cout << "Program Exiting..." << endl;
        }
        else
        {
            cout << "Invalid Choice" << endl;
        }

    } while(choice != 9);

    return 0;
}

void addStudent(vector<Student> &students)
{
    int id;
    string name;
    string dept;
    float cgpa;

    cout << "Enter ID: ";
    cin >> id;

    if(cin.fail())
    {
        cin.clear();
        cin.ignore(1000, '\n');

        cout << "ID must be numeric" << endl;
        return;
    }

    cout << "Enter Name: ";
    cin >> name;

    cout << "Enter Department: ";
    cin >> dept;

    cout << "Enter CGPA: ";
    cin >> cgpa;

    if(cin.fail())
    {
        cin.clear();
        cin.ignore(1000, '\n');

        cout << "CGPA must be numeric" << endl;
        return;
    }

    try
    {
        Student s(id, name, dept, cgpa);

        students.push_back(s);

        cout << "Student Added Successfully" << endl;
    }
    catch(exception &e)
    {
        cout << e.what() << endl;
    }
}

void displayStudents(vector<Student> &students)
{
    int i;

    if(students.size() == 0)
    {
        cout << "No Students Found" << endl;
        return;
    }

    for(i = 0; i < students.size(); i++)
    {
        cout << endl;
        cout << "Student " << i + 1 << endl;
        cout << "-------------------" << endl;

        students[i].display();
    }
}

void searchStudent(vector<Student> &students, int id)
{
    int i;

    for(i = 0; i < students.size(); i++)
    {
        if(students[i].getID() == id)
        {
            students[i].display();
            return;
        }
    }

    cout << "Student Not Found" << endl;
}

void searchStudent(vector<Student> &students, string name)
{
    int i;

    for(i = 0; i < students.size(); i++)
    {
        if(students[i].getName() == name)
        {
            students[i].display();
            return;
        }
    }

    cout << "Student Not Found" << endl;
}

void updateStudent(vector<Student> &students)
{
    int id;
    int i;

    cout << "Enter Student ID To Update: ";
    cin >> id;

    for(i = 0; i < students.size(); i++)
    {
        if(students[i].getID() == id)
        {
            string dept;
            float cgpa;

            cout << "Enter New Department: ";
            cin >> dept;

            cout << "Enter New CGPA: ";
            cin >> cgpa;

            try
            {
                students[i].setDepartment(dept);
                students[i].setCGPA(cgpa);

                cout << "Student Updated Successfully" << endl;
            }
            catch(exception &e)
            {
                cout << e.what() << endl;
            }

            return;
        }
    }

    cout << "Student Not Found" << endl;
}

void deleteStudent(vector<Student> &students)
{
    int id;
    int i;

    cout << "Enter Student ID To Delete: ";
    cin >> id;

    for(i = 0; i < students.size(); i++)
    {
        if(students[i].getID() == id)
        {
            students.erase(students.begin() + i);

            cout << "Student Deleted Successfully" << endl;
            return;
        }
    }

    cout << "Student Not Found" << endl;
}