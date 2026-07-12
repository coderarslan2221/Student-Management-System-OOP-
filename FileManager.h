#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <vector>
#include "Student.h"

using namespace std;

class FileManager
{
public:
    static void saveStudents(vector<Student> &students);
    static void loadStudents(vector<Student> &students);
};

#endif