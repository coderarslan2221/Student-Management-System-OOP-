#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

using namespace std;

class Person
{
protected:
    int id;
    string name;

public:
    Person();
    Person(int, string);

    virtual void display() = 0;

    int getID();
    string getName();

    virtual ~Person();
};

#endif