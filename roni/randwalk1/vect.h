//
// Created by roni on 11/3/25.
//

#ifndef OPERATOR_OVERLOADING_VECT_H
#define OPERATOR_OVERLOADING_VECT_H
#include <iostream>

namespace VECTOR
{
    class Vector
    {
    public:
        enum Mode {RECT, POL};


    private:
        double x;
        double y;
        double mag;
        double ang;
        Mode mode;

        void set_mag();
        void set_ang();
        void set_x();
        void set_y();

    public:
        Vector();
        Vector(double n1, double n2, Mode form = RECT);
        void reset(double n1, double n2, Mode form = RECT);
        ~Vector();

        double xval() const {return x;}
        double yval() const {return y;}
        double magval() const {return mag;} // 크기를 보고한다
        double angval() const {return ang;} // 각도를 보고한다

        void polar_mode();   // 모드를 ’ p ’ 로 설정한다
        void rect_mode(); // 모드를 ’ r ’ 로 설정한다
        // 연산자오버로딩
        Vector operator+(const Vector & b) const;
        Vector operator-(const Vector & b) const;
        Vector operator-() const;
        Vector operator*(double n) const;
        // 프렌드함수
        friend Vector operator*(double n , const Vector & a);
        friend std::ostream &
            operator<<(std::ostream & os , const Vector & v);
    };
} // namespace VECTOR의 끝

#endif //OPERATOR_OVERLOADING_VECT_H