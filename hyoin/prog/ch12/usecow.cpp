/*

프로그래밍 연습 문제
01번 (889 페이지)

cow.h 클래스의 메서드들을 구현하고,
모든 멤버 함수를 사용하는 간단한 프로그램을 작성하라
(cow.h, cow.cpp, uscow.cpp)

*/

#include <iostream>
#include "cow.h"

int main()
{
    using COW::Cow;
    using namespace std;


    cout << "=== Cow 클래스 테스트 시작 ===\n\n";

    // 1. 기본 생성자 호출
    Cow c1;
    cout << "[기본 생성자 호출 후]\n";
    c1.ShowCow();
    cout << endl;

    // 2. 매개변수 있는 생성자 호출
    Cow c2("Cowie", "Grazing", 250.5);
    cout << "[매개변수 생성자 호출 후]\n";
    c2.ShowCow();
    cout << endl;

    // 2-1. 매개변수 있는 생성자 호출
    Cow c4("Coco", "Running", 300.2);
    cout << "[매개변수 생성자 호출 후]\n";
    c4.ShowCow();
    cout << endl;


    // 3. 복사 생성자 호출
    Cow c3 = c2;
    cout << "[복사 생성자 호출] 새로운 Cow 객체에 Cowie 대입\n";
    c3.ShowCow();
    cout << endl;

    // 4. 대입 연산자 호출
    c1 = c3;
    cout << "[대입 연산자 호출] 기본 생성자에 복사 생성자(Cowie) 대입 \n";
    c1.ShowCow();
    cout << endl;

    // 5. 모든 객체가 범위를 벗어날 때 소멸자 호출됨
    cout << "=== Cow 클래스 테스트 종료 ===\n";

    return 0;
}
