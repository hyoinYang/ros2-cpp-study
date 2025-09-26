#include <iostream>
#include <cstring>
#include <string>

void list_04_20(void);
void prog_04_01(void);
void prog_04_02(void);
void prog_04_05(void);
void prog_04_07(void);
void prog_04_08(void);

int main()
{
    list_04_20();
    // prog_04_01();
    // prog_04_02();
    // prog_04_05();
    // prog_04_07();
    // prog_04_08();

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
    //*(ps+1) = 'D';
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
void prog_04_01()
{
    using namespace std;

    char firstName[20];
    char lastName[20];
    char grade;
    int age;

    cout << "영문 퍼스트 네임(이름) : " ;
    cin.getline(firstName, 20);
    cout << "영문 퍼스트 네임 (성) : " ;
    cin.getline(lastName, 20);
    cout << "학생이 원하는 학점: " ;
    cin >> grade;
    cout << "나이: ";
    cin >> age;

    cout << "성명: " << lastName << ", " << firstName << endl;
    cout << "학점: " << char(grade+1) << endl;
    cout << "나이: " << age << endl; 
     
}
void prog_04_02()
{
    using namespace std;
    
    string name;
    string dessert;
    
    cout << "이름 : " ;
    getline(cin, name);

    cout << "디저트 :" ;
    getline(cin, dessert);
    cout << "맛있는 " << dessert << " 디저트를 준비하겠다. " << name << " 님!\n";

}
void prog_04_05()
{
    using namespace std;

    struct CandyBar
    {
        char company[30];
        float weight;
        int calorie;
    };

    CandyBar snack = {
        "Mocha Munch",
        2.3,
        350
    };

    cout << "상표 : " << snack.company << endl;
    cout << "중량 : " << snack.weight << endl;
    cout << "칼로리 : " << snack.calorie << endl;

}
void prog_04_07()
{
    using namespace std;

    struct s_Pizza {
        string name;
        float perimeter;
        float weight;
    };

    s_Pizza pizzas;
    
    cout << "pizza 회사 이름 : ";
    getline(cin, pizzas.name);
    cout << "pizza 지름 : ";
    cin >> pizzas.perimeter;
    cout << "pizza 중량 : ";
    cin >> pizzas.weight;

    cout << pizzas.name << ", " << pizzas.perimeter << ", " << pizzas.weight << endl;
}
void prog_04_08()
{
    using namespace std;

    struct s_Pizza {
        string name;
        float perimeter;
        float weight;
    };

    s_Pizza* p_pizza = new s_Pizza;

    cout << "pizza 지름 : ";
    cin >> p_pizza -> perimeter;
    cin.get();
    cout << "pizza 회사 이름 : ";
    getline(cin, p_pizza -> name);
    cout << "pizza 중량 : ";
    cin >> p_pizza -> weight;

    cout << p_pizza -> name << ", " << p_pizza -> perimeter << ", " << p_pizza -> weight << endl;

    delete p_pizza;

}