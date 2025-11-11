// workermi.cpp -- working class methods with MI
#include "prog_04_person.h"
#include <iostream>
#include <cstdlib> // srand, rand for randomness
#include <ctime> // time for seed
#include <random> // C++11 random

using std::cout;
using std::cin;
using std::endl;
using namespace std;

// Static member for random number generation (for simplicity, using C-style for PokerPlayer::Draw)
// C++11 way is better, let's use C++11 for PokerPlayer
// Initialize random number generator once
namespace 
{
    std::default_random_engine generator(std::time(0));
    std::uniform_int_distribution<int> distribution(1, 52);
}


// Person methods
Person::~Person() { }

void Person::Data() const
{
    cout << "First Name: " << firstname << endl;
    cout << "Last Name: " << lastname << endl;
}

void Person::Show() const
{
    Data();
}

void Person::Get()
{
    cout << "Enter first name: ";
    getline(cin, firstname);
    cout << "Enter last name: ";
    getline(cin, lastname);
}

// Gunslinger methods
void Gunslinger::Get()
{
    cout << "Enter Gunslinger's notch: ";
    cin >> notch;
    cout << "Enter Gunslinger's draw time: ";
    cin >> gunTime;
    while (cin.get() != '\n')
    continue;
}

void Gunslinger::Set()
{
    cout << "Enter Gunslinger's data:\n";
    Person::Get(); 
    Get(); 
}

void Gunslinger::Data() const
{
    cout << "Notch: " << notch << endl;
    cout << "Draw Time: " << gunTime << endl;
}

void Gunslinger::Show() const
{
    cout << "Category: Gunslinger\n";
    Person::Show(); 
    Data(); 
    cout << "==========================" << endl;

}

double Gunslinger::Draw() const
{
    return gunTime; 
}


// PokerPlayer methods
void PokerPlayer::Get()
{
}

void PokerPlayer::Set()
{
    cout << "Enter Poker Player's data:\n";
    Person::Get(); 
    Get(); 
}

void PokerPlayer::Data() const
{
}

void PokerPlayer::Show() const
{
    cout << "Category: Poker Player\n";
    Person::Show();
    cout << "==========================" << endl;

}
int PokerPlayer::Draw()
{
    return distribution(generator);
}


// BadDude methods
void BadDude::Get()
{
    Gunslinger::Get();
    PokerPlayer::Get(); 
}

void BadDude::Set()
{
    cout << "Enter Bad Dude's data:\n";
    Person::Get(); 
    Get(); 
}

void BadDude::Data() const
{
    Gunslinger::Data(); 
    PokerPlayer::Data(); 
}


void BadDude::Show() const
{
    cout << "Category: Bad Dude\n";
    Person::Show(); 
    Data();
    cout << "==========================" << endl;

}

double BadDude::Gdraw() const
{
    return Gunslinger::Draw(); // Gunslinger의 Draw 시간 반환
}

int BadDude::Cdraw()
{
    return PokerPlayer::Draw(); // 새로운 랜덤 카드 값 반환
}