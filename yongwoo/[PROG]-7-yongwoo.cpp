#include <iostream>
using namespace std;

void test_01(void);
char* listing_07_10(char, int);
void listing_07_12(void);
void listing_07_19(void);
    // 배열을 리턴하는 함수
    const double * f1(const double ar[], int n); 
    const double * f2(const double [], int);
    const double * f3(const double *, int);
int main()
{
    // test_01();
    
    // // listing_07_10
    // char* ps = listing_07_10('A', 20);
    // cout << ps << endl;
    // delete [] ps;

    // listing_07_12(); //cin >> a >> b가 어떻게 작동하는지 보기위해서
    // listing_07_19();

    return 0;    
}

void test_01(){
    // int age = 39;
    // int* pd = &age;
    // *pd =41;
    // cout << "age:" << age << endl; 
    // const int * pt = pd;
    // *pd = 42;
    // cout << age << endl;

    // const int **pp2;
    // int *p1;
    // const int *p1;
    // const int n = 1;
    // pp2 = &p1;

    // int age = 39;
    // const int* pt = &age;
    // age = 40;
    // cout << age <<endl;
    // *pt =39 // error

    int age = 39;
    int* p1 = &age;
    const int* p2 = p1;
    cout << "p1 " << p1 << " p2 " << p2 << " &age " << &age << endl;
    cout << "*p1 " << *p1 <<" *p2 " << *p2 << " age " << age <<endl;
}
char* listing_07_10(char c, int n)
{
    char * pstr = new char[n+1];
    pstr[n] = '\0';
    while (n-- > 0)
        cout << n ; // to check if n was evaluated after it was subracted. The answer is yes!
        pstr[n] = c;
    return pstr;
}
void listing_07_12(){
    #pragma execution_character_set("utf-8")
    struct rect{
        double x;
        double y;
    };

    rect rplace;
    cout << "x와 y값을 입력하십시오 : ";
    while (cin >> rplace.x >> rplace.y) // 차례대로 입력된다.
    {
        cout << rplace.x << endl;
        cout << rplace.y << endl;
    }
    cout << "프로그램을 종료합니다.\n";
    
}

void listing_07_19()
{

    double av[3] = {1112.3 , 1542.6, 2227.9};

    // 함수를가리킨다 
    const double *(*p1) (const double *, int)= f1; 
    auto p2 = f2; // C++11 자동 형 변환 
    
    cout << "함수 포인터 : \n"; 
    cout << "주소 \n"; 
    cout << (*p1)(av, 3) << ": " << * (*p1)(av, 3) << endl;
    cout << p1(av, 3) << ": " << *p1(av, 3) << endl;
    cout << (*p2)(av, 3) << ": " << * (*p2)(av, 3) << endl;  
    cout << p2(av, 3) << ": " << *p2(av, 3) << endl;
    

    //함수 포인터들의 배열 pa
    // auto는 리스트 초기화에 사용할 수 없다
    cout << "-------------------------------------" << endl;
    const double* (*pa[3])(const double *, int) = {f1, f2, f3};
    // auto는 단일 값을 초기화 할때는 사용가능
    auto pb = pa; // << pb는 pa주소값 즉 첫번째 원소를 가리킨다
    cout << "\n함수포인터를 원소로 가지는 배열: \n";
    cout << "주소값\n";
    for (int i=0; i < 3; i++)
        cout << pa[i](av,3) << ": " << (*pa[i])(av, 3)<<" : " << *pa[i](av, 3)<< endl;

    cout << "\n함수포인터를 가리키는 포인터\n";
    cout << "주소값\n";
    for (int i=0; i <3; i++)
        cout << pb[i](av,3) << ": " << *pb[i](av,3) << endl;


    // 배열을 리턴하는 함수 포인터를 원소로 가지는 배열을 가리키는 포인터
    cout << "\n포인터를 원소로 가지는 배열을 가리키는 포인터 :\n" ;
    cout << "주소 값\n";
    // auto를 활용한 방법
    auto pc = &pa;
    cout << (*pc)[0](av,3) << ":" << *(*pc)[0](av,3) << endl;
    // 직접 다 지정하는 방법
    const double* (*(*pd)[3])(const double*, int) = &pa;
    // pdb에 리턴 값(f2(av,3), double 지시 포인터)을 저장
    const double * pdb = (*pd)[1](av, 3);
    cout << pdb << ":" << *pdb << endl;

}
    const double * f1(const double *ar, int n)
    {
        return ar;
    }
    const double * f2(const double ar[], int n)
    {
        return ar+1;
    }
    const double * f3(const double ar[], int n)
    {
        return ar+2;
    }
