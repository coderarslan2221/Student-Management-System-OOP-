#include "FileManager.h"
#include <fstream>

void FileManager::saveStudents(vector<Student> &students)
{
    ofstream file("students.txt");

    int i;

    for(i = 0; i < students.size(); i++)
    {
        file << students[i] << endl;
    }

    file.close();
}

void FileManager::loadStudents(vector<Student> &students)
{
    ifstream file("students.txt");

    int id;
    string name;
    string dept;
    float cgpa;

    while(file >> id >> name >> dept >> cgpa)
    {
        Student s(id, name, dept, cgpa);
        students.push_back(s);
    }

    file.close();
}