#include <iostream>
#include <cstring>

using namespace std;

void textin1(void);

int main()
{
    textin1();
    return 0;
}

void textin1()
{
    char ch;
    int count = 0;
    cout << "문자를 입력하시고, 끝내려면 #을 입력하세요: \n";
    cin >> ch;
    
    while (ch != '#')
    {
        //cout << ch;
        ++count;
        cin >> ch;
    }
    cout << endl << count << "문자를 읽었습니다. \n";
    
}