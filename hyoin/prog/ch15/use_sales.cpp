/*
15장 프로그래밍 연습 문제 4

Listing 15.16 (use_sales.cpp)은 nbad_index 예외가 label_val() 메서드를 호출하도록 만들기 위해 각각의 try 블록 뒤에 두 개의 catch 블록을 사용한다.
이 프로그램을 수정하여 각각의 try 블록 뒤에 하나의 catch 블록을 사용하고, 적절할 때에만 label_val()을 호출하는 것을 처리하기 위해 RTTI를 사용하라.

*/



#include <iostream>
#include "sales.h"

int main()
{
    using std::cout;
    using std::cin;
    using std::endl;

    double vals1[12] =
    {
        1220, 1100, 1122, 2212, 1232, 2334,
        2884, 2393, 3302, 2922, 3002, 3544
    };

    double vals2[12] =
    {
        12, 11, 22, 21, 32, 34,
        28, 29, 33, 29, 32, 35
    };

    Sales sales1(2011, vals1, 12);
    LabeledSales sales2("Blogstar",2012, vals2, 12 );

    cout << "try 블록 1 시작:\n";
    try
    {
        int i;
        cout << "Year = " << sales1.Year() << endl;
        for (i = 0; i < 12; ++i)
        {

            cout << sales1[i] << ' ';
            if (i % 6 == 5)
                cout << endl;
        }
        cout << "Year = " << sales2.Year() << endl;
        cout << "Label = " << sales2.Label() << endl;
        for (i = 0; i <= 12; ++i)
        {

            cout << sales2[i] << ' ';
            if (i % 6 == 5)
                cout << endl;
        }
        cout << "try 블록 1 끝\n";
   }
   catch(Sales::bad_index & bad)
   {
        cout << bad.what();
        if (LabeledSales::nbad_index *nb = dynamic_cast<LabeledSales::nbad_index *>(&bad)) // RTTI를 이용해 다운캐스팅
        {
            cout << "Company: " << nb->label_val() << endl;
            cout << "bad index: " << nb->bi_val() << endl;
        }
        else
        {
            cout << "bad index: " << bad.bi_val() << endl;
        }
   }


   cout << "\ntry 블록2 시작:\n";
   try
    {
        sales2[2] = 37.5;
        sales1[20] = 23345;
        cout << "try 블록 2 끝\n";
   }
    catch (Sales::bad_index &bad)
    {
        cout << bad.what();
        if (LabeledSales::nbad_index *nb = dynamic_cast<LabeledSales::nbad_index *>(&bad))
        {
            cout << "Company: " << nb->label_val() << endl;
            cout << "bad index: " << nb->bi_val() << endl;
        }
        else
        {
            cout << "bad index: " << bad.bi_val() << endl;
        }
    }
   cout << "done\n";
   // std::cin.get();
   return 0;
}