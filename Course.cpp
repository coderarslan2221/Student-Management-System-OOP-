#include "Course.h"

Course::Course()
{
    courseID = 0;
    courseName = "None";
    creditHours = 0;
}

Course::Course(int id, string name, int ch)
{
    courseID = id;
    courseName = name;
    creditHours = ch;
}

void Course::display()
{
    cout << "Course ID: " << courseID << endl;
    cout << "Course Name: " << courseName << endl;
    cout << "Credit Hours: " << creditHours << endl;
}

int Course::getCourseID()
{
    return courseID;
}

string Course::getCourseName()
{
    return courseName;
}