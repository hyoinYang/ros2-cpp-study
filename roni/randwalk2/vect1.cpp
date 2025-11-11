//
// Created by Sungmin Hong on 2025. 11. 4..
//
// vect1.cpp
#include <cmath>
#include "vect1.h" // 수정된 헤더 파일 포함
using std::sqrt;
using std::sin;
using std::cos;
using std::atan;
using std::atan2;
using std::cout;

namespace VECTOR
{
    const double Rad_to_deg = 45.0 / atan(1.0);

    // [변경 1] set_mag, set_ang, set_x, set_y 함수 구현부 전체 삭제
    // (더 이상 존재하지 않음)

    // [변경 2] 생성자: mag, ang 설정 로직 제거
    Vector::Vector() //디폴트 생성자
    {
        x = y = 0.0;
        mode = RECT;
        // mag = ang = 0.0; <-- 제거
    }

    // [변경 3] 생성자 (오버로딩):
    // RECT 모드는 x, y만 설정
    // POL 모드는 전달받은 mag, ang(각도)로 x, y를 계산하여 저장
    Vector::Vector(double n1, double n2, Mode form) {
        mode = form;
        if (form == RECT)
        {
            x = n1;
            y = n2;
            // set_mag(); <-- 제거
            // set_ang(); <-- 제거
        }
        else if (form == POL)
        {
            // n1 = mag, n2 = angle(degree)
            double mag = n1;
            double ang_rad = n2 / Rad_to_deg; // 라디안으로 변환
            x = mag * cos(ang_rad);
            y = mag * sin(ang_rad);
            // mag = n1; <-- 제거 (멤버 변수 없음)
            // ang = ang_rad; <-- 제거 (멤버 변수 없음)
            // set_x(); <-- 제거
            // set_y(); <-- 제거
        }
        else
        {
            cout << "Vector () 에 전달된 저 13 의 매개변수가 잘못되었다. \n" ;
            cout << "그래서 벡터를 0으로 설정하였다. \n";
            x = y = 0.0;
            mode = RECT;
            // mag = ang = 0.0; <-- 제거
        }
    }

    // [변경 4] reset 함수: 생성자와 동일한 로직으로 수정
    void Vector::reset(double n1, double n2, Mode form)
    {
        mode = form;
        if (form == RECT) {
            x = n1;
            y = n2;
            // set_mag(); <-- 제거
            // set_ang(); <-- 제거
        }
        else if (form == POL) {
            double mag = n1;
            double ang_rad = n2 / Rad_to_deg;
            x = mag * cos(ang_rad);
            y = mag * sin(ang_rad);
            // mag = n1; <-- 제거
            // ang = ang_rad; <-- 제거
            // set_x(); <-- 제거
            // set_y(); <-- 제거
        }
        else {
            cout << "Vector() 에 전달된 저 13 의 매개변수가 잘못되었다. \n" ;
            cout << "그래서 벡터를 0으로 설정하였다. \n" ;
            x = y = 0.0;
            mode = RECT;
            // mag = ang = 0.0; <-- 제거
        }
    }

    Vector::~Vector() {}
    void Vector::polar_mode() { mode = POL; }
    void Vector::rect_mode() { mode = RECT; }

    // 연산자 오버로딩 (변경 없음)
    // x, y만 사용하므로 기존 로직 그대로 완벽하게 동작합니다.
    Vector Vector::operator+(const Vector & b) const
    {
        return Vector(x + b.x, y + b.y);
    }
    Vector Vector::operator-(const Vector & b) const
    {
        return Vector(x - b.x, y - b.y);
    }
    Vector Vector::operator-() const
    {
        return Vector(-x, -y);
    }
    Vector Vector::operator*(double n) const {
        return Vector(x * n, y * n);
    }

    // 프렌드 함수 (변경 없음)
    Vector operator*(double n, const Vector & a) {
        return a * n;
    }

    // [변경 5] operator<< (출력):
    // POL 모드일 때, v.mag와 v.ang 변수를 직접 참조하는 대신
    // v.magval()과 v.angval() 함수를 호출하여 값을 얻어옴
    std::ostream & operator<<(std::ostream & os, const Vector & v) {
        if (v.mode == Vector::RECT)
            os << "(x,y) = (" << v.x << ", " << v.y << ")";
        else if (v.mode == Vector::POL) {
            // v.mag -> v.magval()로 변경
            // v.ang -> v.angval()로 변경
            os << "(m,a) = (" << v.magval() << ", "
               << v.angval() * Rad_to_deg << ")"; // angval()은 라디안이므로 deg로 변환
        }
        else
            os << "Vector 객체 의 모드 지 정이 틀렸습니다. \n";
        return os;
    }

}// namespace VECTOR의 끝