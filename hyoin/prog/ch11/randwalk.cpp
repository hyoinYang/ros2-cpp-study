/*

프로그래밍 연습 문제
02번 (787페이지)

크기와 각도가 더 이상 데이터 성분으로 저장되지 않도록 Vector 클래스의 헤더 파일과 구현 파일(Listings 11.13과 11.14)을 수정하라. 
대신，그들은 magval()과 angval() 메서드가 호출될 때 즉시 계산되어야한다.

public 인터페이스는 변경하지 않고 그대로 두고(동일한 메서드들이 동일한 매개변수들을 사용해야 한다)， 
private 메서드의 일부와 그 메서드 구현을 포함하여，private 부분을 변경해야 한다

Vector 클래스의 public 인터페이스가 변경되지 않기 때문에 변경이 없는 Listing 11.15를 사용하여， 수정된 버전을 테스트하라. 
(vect1.h, vect1.cpp, randwalk.cpp)

*/


#include <iostream>
#include <cstdlib>      // rand(), srand() prototypes
#include <ctime>        // time() prototype
#include "vect.h"


int main()
{
    using namespace std;
    using VECTOR::Vector;
    srand(time(0));
    double direction;
    Vector step;
    Vector result(0.0, 0.0);
    unsigned long steps = 0;
    double target;
    double dstep;
    cout << "목표 거리를 입력하십시오 (끝내려면 q): ";
    while (cin >> target)
    {
        cout << "보폭을 입력하십시오: ";
        if (!(cin >> dstep))
            break;

        while (result.magval() < target)
        {
            direction = rand() % 360;
            step.reset(dstep, direction, Vector::POL);
            result = result + step;
            steps++;
        }
        cout << steps << " 걸음을 걸은 후 술고래의 현재 위치: \n";
        cout << result << endl;


        result.polar_mode();
        cout << " 또는 \n" << result << endl;
        cout << "걸음당 기둥에서 벗어난 평균 거리 = " << result.magval()/steps << endl;
        steps = 0;
        result.reset(0.0, 0.0);
        cout << "목표 거리를 입력하십시오 (끝내려면 q): ";
    }
    cout << "프로그램을 종료합니다.\n";
    cin.clear();
    while (cin.get() != '\n')
        continue;

    return 0; 
}