// error4.cpp -- logic_error를 사용하는 예외 처리


/* 두 예외 데이터형이 <stdexcept> 헤더 파일이 제공하는 logic_error 클래

스로부터 파생된 클래스가 되도록 Usting 15 .1 1 을 수정하라. 각각의 what () 메서드

가 함수 이름과 그 문제의 본질을 보고하게 하라. 예외 객체들이 잘못된 값을 가지고

있을 필요는 없다. 단지 what () 메서드를 지원하기만 하면 된다. */


#include <iostream>
#include <cmath> // sqrt()
#include <stdexcept>
#include "exc_mean.h"

// 함수 원형 (throw 명세는 C++11 이후 deprecated 되었으나, 문제 맥락상 유지하거나 생략 가능)
double hmean(double a, double b);
double gmean(double a, double b);

int main()
{
    using std::cout;
    using std::cin;
    using std::endl;

    double x, y, z;

    cout << "두 수를 입력하십시오: ";
    while (cin >> x >> y)
    {
        try {
            z = hmean(x, y);
            cout << x << ", " << y << "의 조화평균은 "
                 << z << "입니다." << endl;

            cout << x << ", " << y << "의 기하평균은 "
                 << gmean(x, y) << "입니다." << endl;

            cout << "다른 두 수를 입력하십시오 (끝내려면 q): ";
        }
        catch (bad_hmean & bg) // logic_error & 로 잡아도 됩니다 (다형성)
        {
            // bg.mesg(); 대신 what() 사용
            cout << bg.what() << endl;
            cout << "다시 하십시오." << endl;
            continue;
        }
        catch (bad_gmean & hg)
        {
            // 값(v1, v2)을 출력하는 부분은 제거 (문제 요구사항)
            cout << hg.what() << endl;
            cout << "죄송합니다. 더 이상 진행할 수 없습니다." << endl;
            break;
        }
    }

    cout << "프로그램을 종료합니다." << endl;
    return 0;
}

double hmean(double a, double b)
{
    if (a == -b)
    {
        // 값을 전달하지 않고 메시지만 전달 (기본값 사용 가능)
        throw bad_hmean();
    }
    return 2.0 * a * b / (a + b);
}

double gmean(double a, double b)
{
    if (a < 0 || b < 0)
    {
        throw bad_gmean();
    }
    return std::sqrt(a * b);
}//
// Created by Sungmin Hong on 2025. 11. 18..
//