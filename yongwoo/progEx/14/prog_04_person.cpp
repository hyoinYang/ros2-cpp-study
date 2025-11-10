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
}

double Gunslinger::Draw() const
{
    return gunTime; 
}


// PokerPlayer methods
void PokerPlayer::Get()
{
// PokerPlayer는 추가 데이터 멤버가 없으므로 특별히 할 일 없음
}

void PokerPlayer::Set()
{
    cout << "Enter Poker Player's data:\n";
    Person::Get(); 
    Get(); 
}

void PokerPlayer::Data() const
{
    // PokerPlayer는 추가 데이터 멤버가 없으므로 특별히 할 일 없음
}

void PokerPlayer::Show() const
{
    cout << "Category: Poker Player\n";
    Person::Show(); // 요구 사항: Person show() 함수를 사용
    // Data()는 추가 데이터가 없어 호출하지 않음
}

int PokerPlayer::Draw()
{
    // 1부터 52 사이의 랜덤 카드 값 반환
    return distribution(generator);
}


// BadDude methods
void BadDude::Get()
{
    Gunslinger::Get();
    PokerPlayer::Get(); // 현재는 비어있음
}

void BadDude::Set()
{
    cout << "Enter **Bad Dude**'s data:\n";
    Person::Get(); // Person 부분 설정 (가상 상속 덕분에 한 번만 호출됨)
    Get(); // Gunslinger 및 PokerPlayer 부분 설정
}

void BadDude::Data() const
{
    Gunslinger::Data(); // Notch와 Draw Time
    PokerPlayer::Data(); // 추가 데이터 없음
}


void BadDude::Show() const
{
    cout << "Category: Bad Dude\n";
    Person::Show(); 
    Data();

    cout << "Bad Dude's Draw Time (Gdraw): " << Gdraw() << endl;
    cout << "Next Card Drawn (Cdraw): A random card value (1-52) can be drawn." << endl;
}

double BadDude::Gdraw() const
{
    return Gunslinger::Draw(); // Gunslinger의 Draw 시간 반환
}

int BadDude::Cdraw()
{
    return PokerPlayer::Draw(); // 새로운 랜덤 카드 값 반환
}