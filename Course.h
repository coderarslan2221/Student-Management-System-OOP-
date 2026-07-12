#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include <string>

using namespace std;

class Course
{
private:
    int courseID;
    string courseName;
    int creditHours;

public:
    Course();
    Course(int, string, int);

    void display();

    int getCourseID();
    string getCourseName();
};

#endif