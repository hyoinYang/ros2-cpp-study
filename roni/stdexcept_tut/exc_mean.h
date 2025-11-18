// exc_mean.h -- std::logic_error를 상속받는 예외 클래스들
#include <iostream>
#include <stdexcept> // logic_error를 위해 필요
#include <string>

class bad_hmean : public std::logic_error
{
public:
    // logic_error의 생성자는 string을 받아 what()이 출력할 메시지로 저장합니다.
    explicit bad_hmean(const std::string& what_arg = "hmean(): invalid arguments: a = -b")
        : std::logic_error(what_arg) {
    //explicit는 "문자열 하나 툭 던져주면 알아서 객체로 바꾸지 마. 내가 괄호 열고 생성자 호출할 때만 객체로 만들어."
    }


};

class bad_gmean : public std::logic_error
{
public:
    explicit bad_gmean(const std::string& what_arg = "gmean(): arguments should be >= 0")
        : std::logic_error(what_arg)
    {
    }
    // "나(bad_hmean)를 만들 때 에러 메시지(std::string)를 줘.
    // 무거우니까 복사하지 말고 그냥 원본 보여주고(&), 대신 내가 수정은 안 할게(const).
    // 정 할 말 없으면 그냥 비워둬(=).
    // 내가 미리 준비해 둔 기본 메시지("hmean()...")를 쓸 테니까."
};

// 생성자 호출은 코드로만 존재하던 클래스를 **실제 메모리에 살아있는 객체로 탄생시키는 순간