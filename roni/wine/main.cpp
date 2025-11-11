// main.cpp (또는 pe14-1.cpp) -- Wine 클래스를 사용한다
#include <iostream>
#include "winec.h"

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;

    cout << "와인 이름을 입력하시오: ";
    char lab[50];
    cin.getline(lab, 50);

    cout << "수확 년도 개수를 입력하시오: ";
    int yrs;
    cin >> yrs;

    Wine holding(lab, yrs); // 첫 번째 생성자 호출

    // 레이블과 수확 년도 개수를 저장한다
    // 배열에 yrs개의 원소를 제공한다
    holding.GetBottles(); // 연도, 와인 수량을 입력하도록 요청한다
    holding.Show(); // 객체 내용을 디스플레이한다

    const int YRS = 3;
    int y[YRS] = {1993, 1995, 1998};
    int b[YRS] = { 48,  60,  72};

    // 새 객체를 생성하고, 배열 y와 b에 있는 데이터를 사용하여 초기화한다
    Wine more("Gushing Grape Red", YRS, y, b); // 두 번째 생성자 호출
    more.Show();

    cout << more.Label() << " 전체 수량" // Label() 메서드 사용
         << ": " << more.sum() << endl; // sum() 메서드 사용

    cout << "프로그램을 종료합니다.\n";

    return 0;
}