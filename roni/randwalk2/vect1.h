// vect1.h
#ifndef OPERATOR_OVERLOADING_VECT_H
#define OPERATOR_OVERLOADING_VECT_H

#include <iostream>
#include <cmath> // 1. sqrt, atan2를 사용하기 위해 여기에 포함

namespace VECTOR
{
    class Vector
    {
    public:
        enum Mode {RECT, POL};

        // [변경 1] private 멤버 변수에서 mag, ang 제거
    private:
        double x;
        double y;
        // double mag;  <-- 제거
        // double ang;  <-- 제거
        Mode mode;

        // [변경 2] 불필요해진 private 헬퍼 함수 제거
        // void set_mag(); <-- 제거
        // void set_ang(); <-- 제거
        // void set_x(); <-- 제거
        // void set_y(); <-- 제거

    public:
        Vector();
        Vector(double n1, double n2, Mode form = RECT);
        void reset(double n1, double n2, Mode form = RECT);
        ~Vector();

        double xval() const {return x;}
        double yval() const {return y;}

        // [변경 3] magval()과 angval()이 즉시 계산하도록 변경
        //            (public 인터페이스 자체는 변경되지 않음)
        double magval() const { return std::sqrt(x * x + y * y); }
        double angval() const {
            if (x == 0.0 && y == 0.0)
                return 0.0;
            else
                return std::atan2(y, x); // 라디안 값 반환
        }

        void polar_mode();
        void rect_mode();

        // 연산자 오버로딩 (변경 없음)
        Vector operator+ (const Vector & b) const;
        Vector operator-(const Vector & b) const;
        Vector operator-() const;
        Vector operator*(double n) const;

        // 프렌드 함수 (변경 없음)
        friend Vector operator*(double n , const Vector & a);
        friend std::ostream &
            operator<<(std::ostream & os , const Vector & v);
    };
}

#endif //OPERATOR_OVERLOADING_VECT_H//
// Created by Sungmin Hong on 2025. 11. 4..
//

#ifndef RANDWALK2_VECT_H
#define RANDWALK2_VECT_H

#endif //RANDWALK2_VECT_H