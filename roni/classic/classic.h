#ifndef CLASSIC_H_
#define CLASSIC_H_

#include <iostream>

// CD 디스크를 나타내는 기본 클래스
class Cd {
private:
    char *  performers; // 동적 할당 될 포인터
    // char performers[50];
    char * label; // 동적 할당 될 포인터
    // char label[20];
    int selections;   // 수록 곡 수
    double playtime;  // 분 단위의 연주 시간

public:
    Cd(const char * s1, const char * s2, int n, double x);
    Cd(const Cd & d);
    Cd();
    virtual ~Cd(); // 가상 소멸자
    virtual void Report() const; // CD의 모든 데이터를 보고한다
    Cd & operator=(const Cd & d);
};

// Classic CD를 나타내는 파생 클래스
class Classic : public Cd {
private:
    char * main_track;
    // char main_track[100]; // 대표곡을 저장할 배열

public:
    Classic(const char * s1, const char * s2, const char * s3, int n, double x);
    Classic(const Classic & c);
    Classic();
    virtual ~Classic();// 가상 소멸자
    virtual void Report() const override; // Classic의 모든 데이터를 보고한다
    Classic & operator=(const Classic & c);
};

#endif