// winec.h -- Wine 클래스 선언

#ifndef WINEC_H_
#define WINEC_H_

#include <iostream>
#include <string>
#include <valarray> // valarray를 사용하기 위해 포함
#include <utility>   // std::pair를 사용하기 위해 포함

// 1. 문제에서 요구한 typedef 정의
// std::valarray<int>를 ArrayInt라는 별명으로 부름
typedef std::valarray<int> ArrayInt;

// "연도 배열"과 "수량 배열"을 한 쌍(pair)으로 묶음
// std::pair<ArrayInt, ArrayInt>를 PairArray라는 별명으로 부름
typedef std::pair<ArrayInt, ArrayInt> PairArray;


// 2. Wine 클래스 정의
// Wine class는 private으로 string과 PairArray를 상속받는다
class Wine : private std::string, private PairArray
{
private:

    int num_years;    // 수확 연도 개수
    //string과 PairArray를 상속받음
    // 멤버 변수에 담겨졌던 이전 코드와 달리 직접 생성자를 l이라는 이름으로 호출
    // PairArray(ArrayInt(yr, y), ArrayInt(bot, y))에 직접 호출

public:
    // 3. 생성자 선언 (main에서 두 가지 방식으로 호출함)

    // (1) 이름과 연도 개수만 받는 생성자 (holding 객체용)
    Wine(const char * l, int y);

    // (2) 모든 데이터를 받는 생성자 (more 객체용)
    Wine(const char * l, int y, const int yr[], const int bot[]);


    // 4. 멤버 함수 선언 (main에서 요구하는 기능들)

    // 사용자로부터 연도와 수량을 입력받는 함수
    void GetBottles();

    // 와인 정보를 출력하는 함수
    void Show() const;

    int sum() const;

    // 와인 이름을 반환하는 함수
    // const std::string & : 이름을 복사하지 않고 원본을 참조하여 반환 (효율적)
    const std::string & Label() const { return (const std::string &)(*this); }

    // 총 수량을 계산하여 반환하는 함수
    // int sum() const;
}; // 클래스 정의 끝 (세미콜론 필수)

#endif // WINEC_H_