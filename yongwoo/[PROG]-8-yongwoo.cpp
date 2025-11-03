#include <iostream>

//08.11
template <class Any>
void Swap(Any &a, Any &b);
void listing_08_11(void);


// MAIN
int main()
{
    listing_08_11();
    return 0;
}
//08.11
void listing_08_11()
{
    using namespace std;
    int i = 10;
    int j = 20;
    cout << "Before i,j = " << i << "," << j <<".\n";
    Swap(i,j);
    cout <<"After i,j = " << i <<"," <<j << ".\n";

    double x = 24.5;
    double y = 81.7;
    cout << "Before x,y = " << x << "," << y <<".\n";
    Swap(x,y);
    cout <<"After x,y = " << x <<"," <<y << ".\n";

//     int a = 20;
//     double b = 81.7;
//     cout << "Before a,b = " << a << "," << b <<".\n";
//     Swap(a,b); //Error 발생
//     cout <<"After a,b = " << a <<"," << b << ".\n";
}
template <class Any>
void Swap(Any &a, Any &b)
{
    Any temp;
    temp = a;
    a = b;
    b= temp;
}