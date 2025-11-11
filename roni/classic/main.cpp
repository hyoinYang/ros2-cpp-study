// pe13-01.cpp -- 13장 프로그래밍 연습 1 테스트 프로그램
// classic.cpp와 함께 컴파일함
#include <iostream>
using namespace std;
#include "classic.h" // #include cd.h를 포함한다

void Bravo(const Cd & disk);

int main()
{
    Cd c1("Beatles", "Capitol", 14, 35.5);
    Classic c2 = Classic("Piano Sonata in B flat, Fantasia in C",
                         "Alfred Brendel", "Philips", 2, 57.17);
    Cd *pcd = &c1;

    cout << "객체를 직접 사용한다:\n";
    c1.Report();    // Cd 메서드를 사용한다
    c2.Report();    // Classic 메서드를 사용한다

    cout << "\n객체를 지시하는 Cd * 포인터를 사용한다:\n";
    pcd->Report();  // Cd 객체에 Cd 메서드를 사용
    pcd = &c2;
    pcd->Report();  // Classic 객체에 Classic 메서드 사용 (virtual 덕분에)

    cout << "\nCd 참조 매개변수를 사용하여 함수를 호출한다:\n";
    Bravo(c1);
    Bravo(c2);

    cout << "\n대입을 테스트한다:\n";
    Classic copy;
    copy = c2;
    copy.Report();

    return 0;
}

void Bravo(const Cd & disk)
{
    disk.Report();
}