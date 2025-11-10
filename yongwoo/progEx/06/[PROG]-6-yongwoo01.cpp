#include <iostream>
using namespace std;

void listing_06_2(void);
void listing_07_7(void);
int fill_array(double ar[], int limit);
void show_array(const double ar[], int n);
void revalue(double r, double ar[], int n);

int main()
{
    // listing_06_2();
    listing_07_7();

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
void listing_07_7(){
    const int Max = 5;
    double properties[Max];

    int size = fill_array(properties, Max);
    show_array(properties, size);
    if (size >0)
    {
        cout << "Enter your factor: ";
        double factor;
        while (!(cin>>factor))
        {
            cin.clear(); // 실패 플래그를 지워서 입력을 다시 받을 수 있게 함
            while (cin.get()!='\n') //cin.get()은 하나씩만 character 하나를 불러옴, 입력큐에 쌓인 쓰레기 입력을 흘려보냄
                continue;
            cout << "잘못입력함 , 수치를 입력하세요: ";
        }
        revalue(factor, properties, size);
        show_array(properties, size);

    }
    cout << "프로그램을 종료\n";
    cin.get();
    cin.get();
}

int fill_array(double ar[], int limit)
{
    double temp;
    int i;
    for(i=0; i<limit; i++)
    {
        cout << (i+1) << "번 부동산의 가격: $";
        cin >> temp;
        if(!cin){
            cin.clear();
            while (cin.get() !='\n'){
                cout << 1;
                continue;
            }

            cout << "입력불량; 입력과정을 끝내겠습니다.\n";
            break;
        }
        else if (temp<0)
        {
            break;
        }
        ar[i] = temp;
    }
    return i;
}

void show_array(const double ar[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << (i+1) << "번 부동산: $";
        cout << ar[i] << endl;
    }
    
}

void revalue(double r, double ar[], int n)
{
    for (int i = 0; i < n; i++)
        ar[i] *= r;
}