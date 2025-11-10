#include "classic.h"
#include <cstring>
#include <iostream>

using namespace std;

void Classic::Report() const
{
    cout << "Title: " << title << endl;

}
Classic::Classic()
    : Cd()
{
    title[0] = '\0';
}

Classic::Classic(char * t, char * sl , char * s2 , int n , double x)
    : Cd(sl, s2, n, x)
{
    strncpy(title, t, 49);
    title[49] = '\0';
}

Classic & Classic::operator=(const Classic & d)
{
    if (this == &d) return *this;

    Cd::operator=(d);

    strncpy(title, d.title, sizeof(title) - 1);
    title[sizeof(title) - 1] = '\0';

    return *this;
}

Classic::~Classic()
{
}

