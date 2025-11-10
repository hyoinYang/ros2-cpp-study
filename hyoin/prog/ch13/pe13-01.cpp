// pe13-01.cpp -- 13장 프로그래밍 연습 1 테스트 프로그램
/*

CD의 대표곡을 다타내는 문자열을 저장하기 위한 char 형의 배열을 하나 추가시켜, Classic 클래스를 파생시켜라
기초 클래스의 어떤 함수가 가상일 것을 요구한다면 그렇게 되도록 기초 클래스를 수정하라
불필요한 메서드가 선언되어 있다면 찾아서 제거하라
pe13-01.cpp를 사용하여 사용자가 작성한 코드들이 바르게 동작하는지 테스트하라

*/

#include <iostream>
using namespace std;
#include "classic.h"

void Bravo(const Cd & disk);
int main ()
{
    Cd c1("Beatles" , "Capitol" , 14 , 35.5);
    Classic c2 = Classic("P iano Sonata in B flat , Fantasia in C",
        "Alfred Brendel", "Philips", 2, 57.17);

    Cd *pcd = &c1;

    cout << "객체를 직접 사용한다: \n";
    c1.Report();
    c2.Report();

    cout << "객체를 지시하는 Cd * 포인터를 사용한다: \n";
    pcd -> Report();
    pcd = &c2;
    pcd -> Report();

    cout << "Cd 참조 매개변수를 사용하여 함수를 호출한다: \n";
    Bravo(c1);
    Bravo(c2);

    cout << "대입을 테스트한다: \n";
    Classic copy;
    copy = c2;
    copy.Report();

    return 0;

}

void Bravo(const Cd & disk)
{
    disk.Report();
}