#include <iostream>
using namespace std;

void listing_06_2(void);

int main()
{
    listing_06_2();
    return 0;   
}

void listing_06_2() {
    char ch;

    cout << "타이핑 하세요 \n";
    cin.get(ch);
    
    while (ch != '.')
    {
        if(ch=='\n')
            cout << ch; //개행문자일때는 입력을 그대로 받음 -> 개행되고 입력 끝남
        else
            // cout << ++ch; //1
            //cout << ch++; //2
            //cout << ch; //2
            cout << ch +1; //3 -> ch가 int로 변환되면서 1을 더하고 int로 출력
        cin.get(ch);
    }
    
}