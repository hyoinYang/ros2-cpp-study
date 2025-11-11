#include "classic.h"
#include <cstring> // strncpy, strlen 등을 사용하기 위해
#include <iostream>

using std::cout;
using std::endl;

// --- Cd 클래스 메서드 구현 ---

// 매개변수가 있는 생성자
Cd::Cd(const char * s1, const char * s2, int n, double x)
{
    // strncpy(performers, s1, 49);
    performers = new char[strlen(s1) + 1];
    // performers[49] = '\0'; // 안전을 위해 null 종단
    strcpy(performers, s1);
    label = new char[strlen(s2) + 1];
    // label[19] = '\0';
    strcpy(performers, s2);
    selections = n;
    playtime = x;
}

// 복사 생성자 (깊은 복사)
Cd::Cd(const Cd & d) {
    performers = new char[strlen(d.performers) + 1];
    strcpy(performers, d.performers);
    label = new char[strlen(d.label) + 1];
    strcpy(label, d.label);
    selections = d.selections;
    playtime = d.playtime;
}

// 기본 생성자
Cd::Cd()
{
    performers = new char[1];
    performers[0] = '\0'; // 빈 문자열로 초기화
    label = new char[1];
    label[0] = '\0';
    selections = 0;
    playtime = 0.0;
}

// 소멸자 (메모리 해제)
Cd::~Cd()
{
    delete [] performers; // new[]로 할당한 것은 delete[]로 해제
    delete [] label;
}
// Report() 메서드
void Cd::Report() const {
    cout << "Performers: " << performers << endl;
    cout << "Label: " << label << endl;
    cout << "Selections: " << selections << endl;
    cout << "Playtime: " << playtime << " minutes" << endl;
}

// 대// 대입 연산자 (깊은 복사)
Cd & Cd::operator=(const Cd & d) {
    if (this == &d) // 1. 자가 대입 확인
        return *this;

    // 2. 기존 메모리 해제
    delete [] performers;
    delete [] label;

    // 3. 새 메모리 할당 및 복사 (복사 생성자와 동일)
    performers = new char[strlen(d.performers) + 1];
    strcpy(performers, d.performers);
    label = new char[strlen(d.label) + 1];
    strcpy(label, d.label);
    selections = d.selections;
    playtime = d.playtime;

    return *this; // 4. *this 참조 반환
}

// --- Classic 클래스 메서드 구현 ---

// 매개변수가 있는 생성자
Classic::Classic(const char * s1, const char * s2, const char * s3, int n, double x)
    : Cd(s1, s2, n, x) // 기본 클래스 생성자 호출 (필수)
{
    main_track = new char[strlen(s3) + 1];
    strcpy(main_track, s3);
}

// 복사 생성자
Classic::Classic(const Classic & c)
    : Cd(c) // 기본 클래스 복사 생성자 호출 (필수)
{
    main_track = new char[strlen(c.main_track) + 1];
    strcpy(main_track, c.main_track);
}

// 기본 생성자
Classic::Classic()
    : Cd() // 기본 클래스 기본 생성자 호출
{
    main_track = new char[1];
    main_track[0] = '\0';
}

// 소멸자
Classic::~Classic() {
    delete [] main_track;
    // 기본 클래스(Cd)의 소멸자는 자동으로 호출됨
}

// Report() 메서드 (오버라이드)
void Classic::Report() const {
    Cd::Report(); // 기본 클래스의 Report() 호출
    cout << "Main Track: " << main_track << endl;
}

// 대입 연산자
Classic & Classic::operator=(const Classic & c) {
    if (this == &c) // 1. 자가 대입 확인
        return *this;

    Cd::operator=(c); // 2. 기본 클래스 대입 연산자 호출 (필수)

    // 3. 파생 클래스 멤버의 기존 메모리 해제
    delete [] main_track;

    // 4. 새 메모리 할당 및 복사
    main_track = new char[strlen(c.main_track) + 1];
    strcpy(main_track, c.main_track);

    return *this; // 5. *this 참조 반환
}