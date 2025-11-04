// stonewt.cpp -- Stonewt methods and operator overloads
#include "prog_5_stonewt.h"
#include <iostream>
#include <cmath> // round() 함수를 사용하기 위해 포함

using std::cout;

int main()
{
    using std::endl;

    // 1. Stonewt 객체 생성
    Stonewt minnie(11, 7.5);  // 11 stone, 7.5 pounds
    Stonewt mickie(100.0);    // 100.0 pounds
    Stonewt donald(20, 0.0);  // 20 stone

    Stonewt total;
    Stonewt diff;
    Stonewt multiple;

    cout << "--- Initial Weights ---\n";
    minnie.set_stone_mode();
    cout << "Minnie's weight: " << minnie << endl; 
    mickie.set_double_pound_mode();
    cout << "Mickie's weight: " << mickie << endl;
    donald.set_int_pound_mode();
    cout << "Donald's weight: " << donald << endl;
    
    cout << "\n--- Operator Overloading Tests ---\n";

    // 2. 덧셈 테스트: + 연산자 사용
    total = minnie + mickie;
    cout << "Total (Minnie + Mickie):\n";
    total.set_stone_mode();
    cout << "  Stone mode: " << total << endl; // STONE 모드로 출력
    total.set_double_pound_mode();
    cout << " Double Pound mode: " << total << endl; // DOUBLE_POUND 모드로 출력
    
    // 3. 뺄셈 테스트: - 연산자 사용
    diff = donald - minnie;
    cout << "\nDifference (Donald - Minnie):\n";
    diff.set_int_pound_mode();
    cout << "  Int Pound mode: " << diff << endl; // INT_POUND 모드로 출력
    diff.set_double_pound_mode();
    cout << "  DOUBLE_POUND mode: "  << diff << endl; 

    // 4. 곱셈 테스트: * 연산자 사용
    multiple = minnie * 2.5;
    cout << "\nMinnie * 2.5 (Multiple):\n";
    multiple.set_stone_mode();
    cout << "  Stone mode: " << multiple << endl; 
    multiple.set_double_pound_mode();
    cout << "  DOUBLE_POUND mode: " << multiple << endl; 
    
    cout << "\n--- Final State Change Test ---\n";
    Stonewt test_obj(18.9); 
    cout << "Weight 18.9 lbs:\n";
    test_obj.set_stone_mode();
    cout << "  STONE mode: " << test_obj << endl; // 1 stone, 4.9 pounds
    test_obj.set_int_pound_mode();
    cout << "  INT_POUND mode: " << test_obj << endl; // 19 integer pounds (반올림)
    test_obj.set_double_pound_mode();
    cout << "  DOUBLE_POUND mode: " << test_obj << endl; // 18.9 pounds

    return 0;
}
Stonewt::Stonewt(double lbs)
{
    stone = int (lbs) / Lbs_per_stn;    // integer division
    pds_left = int (lbs) % Lbs_per_stn + lbs - int(lbs);
    pounds = lbs;
    state = DOUBLE_POUND; 
}

Stonewt::Stonewt(int lbs)
{
    stone = lbs / Lbs_per_stn;    // integer division
    pds_left = lbs % Lbs_per_stn;
    pounds = lbs;
    state = INT_POUND; 
}

Stonewt::Stonewt(int stn, double lbs)
{
    stone = stn;
    pds_left = lbs;
    pounds = stn * Lbs_per_stn + lbs;
    state = STONE;
}

Stonewt::Stonewt()
{
    stone = pounds = pds_left = 0;
    state = STONE;
}

Stonewt::~Stonewt()
{
}

// --- 산술 연산자 오버로딩 ---

Stonewt Stonewt::operator+(const Stonewt & st) const
{
    return Stonewt(pounds + st.pounds);
}
Stonewt Stonewt::operator-(const Stonewt & st) const
{
    return Stonewt(pounds - st.pounds);
}
Stonewt Stonewt::operator*(double mult) const
{
    return Stonewt(pounds * mult);
}


std::ostream & operator<<(std::ostream & os, const Stonewt & st)
{
switch (st.state)
    {
        case Stonewt::STONE:
            os << st.stone << " stone, " << st.pds_left << " pounds";
            break;
        case Stonewt::INT_POUND:
            os << int(std::round(st.pounds)) << " integer pounds"; 
            break;
        case Stonewt::DOUBLE_POUND:
            os << st.pounds << " pounds";
            break;
        default:
            os << "Unknown format for Stonewt object";
    }
    return os;
}