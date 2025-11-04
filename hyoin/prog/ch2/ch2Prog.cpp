
/*
프로그래밍 연습 문제
07번 (70페이지)

시간 값과 분 값의 입력을 사용자에게 요청하는 프로그램을 작성하라

*/

#include <iostream>

void showTime(int hour, int minute);

int main(){
    using namespace std;

    int hour, minute;
    cout << "시간 값을 입력하시오: "; 
    cin >> hour;
    
    cout << "분 값을 입력하시오: " ;
    cin >> minute;

    showTime(hour, minute);

    return 0;
    
}

void showTime(int hour, int minute){
    using namespace std;
    
    cout << "시각: " << hour << ":" << minute << endl;
}