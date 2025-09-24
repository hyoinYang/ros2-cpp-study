#include <iostream>
#include <cstring>

void list_04_20(void);

int main()
{
    list_04_20();
    return 0;
}

void list_04_20()
{
    // 문자열 상수와 포인터와의 관계
    using namespace std;
    char animal[20] = "bear";
    char* ps;
    
    //cout << "동물를 입력하세요. ";
    //cin >> animal;

    ps = animal;
    //ps = "bear"; // 문자열 상수는 char*로 변환이 안됨
    cout <<"ps : " << ps << "s!\n";
    cout << "* ps : " << *ps << endl;
    cout << "ps[0] : " << ps[0] << endl;
    cout << "&ps : " << &ps << endl;
    cout << "&animal : " << &animal << endl;
    cout << "&animal[0] : " << &animal[0] << endl;
    cout << "(int *) ps : " << (int *) ps << endl;
    cout << "(int *) animal : " << (int*) animal << endl;


    cout << "animal : " << animal << endl;
}