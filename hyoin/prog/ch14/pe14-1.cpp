/*

14장 프로그래밍 연습 문제 1

Wine 클래스는 특정 와인에 대한 정보를 저장하는 클래스이다.
이 클래스는 다음과 같은 데이터를 가진다:
    와인의 이름(std::string 사용)
    포도 수확 년도들과, 해당 년도별 생산량(병 수)을 저장하는 Pair 객체
        여기서 Pair는 두 개의 std::valarray<int>를 멤버로 가진다.
            첫 번째 valarray<int>: 각 수확 년도 (예: 1993, 1995, 1998)
            두 번째 valarray<int>: 각 년도에 생산된 병 수 (예: 48, 60, 72)
즉, 하나의 Wine 객체는 “이름 + 여러 년도별 생산량” 정보를 모두 가지고 있다.

코드의 가독성을 높이기 위해 다음 별칭을 사용한다:
    typedef std::valarray<int> ArrayInt;
    typedef Pair<ArrayInt, ArrayInt> PairArray;


[필수 생성자]
Wine(const char l, int y, const int yr[], const int bot[])*
    → 와인 이름 l, 수확년도 개수 y, 년도 배열 yr[], 병 수 배열 bot[]을 이용해 초기화.

Wine(const char l, int y)*
    → 이름만 지정하고, 수확년도 개수(y)만큼의 배열을 미리 만들어둔다.
    (값은 나중에 GetBottles()로 입력받음)

[필수 메서드]

GetBottles()
    → 사용자가 수확년도와 병 수를 직접 입력할 수 있도록 한다.

Label()
    → 와인 이름(label)을 반환한다.

sum()
    → 모든 년도의 병 수를 더한 총 생산량을 반환한다


*/


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

    Wine holding(lab, yrs);

    holding.GetBottles();
    holding.Show();

    cout << holding.Label() << " 전체 수량"
        << ": " << holding.sum() << endl;

    const int YEARS = 3;
    int y[YEARS] = {1993, 1995, 1998};
    int b[YEARS] = {48, 60, 72};

    Wine more("Gushing Grape Red", YEARS, y, b);
    more.Show();
    cout << more.Label() << " 전체 수량"
        << ": " << more.sum() << endl;
    
    cout << "프로그램을 종료합니다." << endl;

    return 0;
}