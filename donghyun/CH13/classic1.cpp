#include "classic1.h"
#include <iostream>
#include <cstring>

Cd::Cd(const char* s1, const char* s2, int n, double x)
{
    performers = new char[strlen(s1) + 1];
    label = new char[strlen(s2) + 1];
    strcpy(performers, s1);
    strcpy(label, s2);
    selections = n;
    playtime = x;
}

Cd::Cd(const Cd& d)
{
    performers = new char[strlen(d.performers) + 1];
    label = new char[strlen(d.label) + 1];
    strcpy(performers, d.performers);
    strcpy(label, d.label);
    selections = d.selections;
    playtime = d.playtime;
}

void Cd::Report() const
{
    std::cout << "연주자 : " << performers
        << "\n레이블 : " << label
        << "\n수록 곡목 수 : " << selections
        << "\n연주 시간 : " << playtime << '\n';
}

Cd::~Cd()
{
    delete[] performers;
    delete[] label;
}

Cd& Cd::operator=(const Cd& d)
{
    if (this == &d)
        return *this;

    delete[] performers;
    delete[] label;

    performers = new char[strlen(d.performers) + 1];
    label = new char[strlen(d.label) + 1];

    strcpy(performers, d.performers);
    strcpy(label, d.label);

    selections = d.selections;
    playtime = d.playtime;
    return *this;
}

Classic::Classic(const char* s3,const char* s1,const char* s2,int n,double x)
    : Cd(s1,s2,n,x)
{
    title = new char[strlen(s3) + 1];
    strcpy(title, s3);
}

Classic::Classic(const Cd& d, const char* s3) : Cd(d)
{
    title = new char[strlen(s3) + 1];
    strcpy(title, s3);
}

Classic::Classic(const Classic& d) : Cd(d)
{
    title = new char[strlen(d.title) + 1];
    strcpy(title, d.title);
}

Classic::~Classic()
{
    delete[] title;
}

Classic& Classic::operator=(const Classic& d)
{
    if (this == &d)
        return *this;

    Cd::operator=(d);

    delete[] title;
    title = new char[strlen(d.title) + 1];
    strcpy(title, d.title);
    return *this;
}

void Classic::Report() const
{
    std::cout << "대표곡 : " << title << '\n';
    Cd::Report();
}
