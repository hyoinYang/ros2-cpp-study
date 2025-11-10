#include <string>
#include <iostream>
#include <valarray>
#include "pairs.cpp"

using namespace std;

class Wine
{
    private:
        typedef valarray<int> ArrayInt;
        typedef Pair<ArrayInt, ArrayInt> PairArray;
        
        string label;
        int years;
        PairArray data; // 수확연도, 병 수를 한꺼번에 저장

    public:
        Wine(const char * l, int y, const int yr[], const int bot[]);
        Wine(const char * l, int y);
        void GetBottles(); // 수확연도와 병 수 입력 받기
        void Show() const; // 멤버변수 변경 불가
        const string& Label(); // string 객체의 상수 참조 반환. (string 객체에 직접 접근 방지)
        int sum() const;

};