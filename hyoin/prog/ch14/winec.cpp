#include "winec.h"
#include <cstring>
#include <string>


Wine::Wine(const char * l, int y, const int yr[], const int bot[])
    :label(l), years(y), data(ArrayInt(yr, y), ArrayInt(bot, y))
{}

Wine::Wine(const char * l, int y)
    : label(l), years(y), data(ArrayInt(y), ArrayInt(y))
{}

void Wine::GetBottles()
{

    using std::cin;
    using std::cout;
    using std::endl;

    cout << years <<"년 간의 " << label << " 데이터를 입력하시오: " << endl;
    
    for (int i = 0; i < years; i++)
    {

        int temp_year = 0;
        int temp_cnt = 0;

        cout << "년도를 입력하시오: ";
        cin >> data.first()[i];

        cout << "수량을 입력하시오: ";
        cin >> data.second()[i];
    }
}

void Wine::Show() const
{
    using std::cin;
    using std::cout;
    using std::endl;

    cout << "와인: " << label << endl;
    cout << "\t년도\t수량" << endl; 
    
    for (int i = 0; i < years; i++)
    {
        cout << "\t" << data.first()[i] << "\t" << data.second()[i] << endl;
    }
}

const string& Wine::Label()
{
    return label; // label 객체 자체를 참조로 돌려줌. 
}

int Wine::sum() const
{
    int sum = 0;

    for (int i = 0; i < years; i++)
    {
        sum += data.second()[i];
    }

    return sum;
}