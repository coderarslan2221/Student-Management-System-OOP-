#include "Person.h"

Person::Person()
{
    id = 0;
    name = "Unknown";
}

Person::Person(int i, string n)
{
    id = i;
    name = n;
}

int Person::getID()
{
    return id;
}

string Person::getName()
{
    return name;
}

Person::~Person()
{
}