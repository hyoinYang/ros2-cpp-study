// vect.cpp -- methods for the Vector class
#include <cmath>
#include "vect.h"   // includes <iostream>
using std::sqrt;
using std::sin;
using std::cos;
using std::atan;
using std::atan2;
using std::cout;

namespace VECTOR
{

    // 1 라디안 내의 각도를 계산하여라 (1 라디안에 대한 degree 값을 계산)
    const double Rad_to_deg = 45.0 / atan(1.0);
    // 반드시 약 57.2957795130823 값이 되어야 함

    double Vector::magval() const {
        return std::sqrt(x * x + y * y);
    } // 크기를 보고한다
     
    double Vector::angval() const
        {
        if (x == 0.0 && y == 0.0)
            return 0.0;
        else
            return std::atan2(y, x);  
        } // 각도를 보고한다


    // 극좌표를 사용하여 x를 설정한다
    void Vector::set_x()
    {
        x = magval() * cos(angval());
    }

    // 극좌표를 사용하여 y를 설정한다
    void Vector::set_y()
    {
        y = magval() * sin(angval());
    }

    // public 메서드들
    Vector::Vector() // 디폴트 생성자
    {
        x = y = 0.0;
        mode = RECT;
    }

    // form이 r이면 직각좌표로부터 벡터를 구성한다
    // form이 p이면 극좌표로부터 벡터를 구성한다
    Vector::Vector(double n1, double n2, Mode form)
    {
        mode = form;
        if (form == RECT)
         {
             x = n1;
             y = n2;
        }
        else if (form == POL)
        {
            double mag = n1; // 임시 지역 변수
            double ang = n2 / Rad_to_deg; // 각도를 라디안으로 변환
            x = mag * cos(ang);
            y = mag * sin(ang);
        }
        else
        {
             cout << "Vector()에 전달된 제 3의 매개변수가 잘못되었다.\n";
             cout << "그래서 벡터를 0으로 설정하였다.\n";
             x = y = 0.0;
             mode = RECT;
        }
    }

    // form이 RECT이면 직각좌표로부터 벡터를 구성한다 (디폴트)
    // form이 POL이면 극 좌표로부터 벡터를 구성한다
    void Vector:: reset(double n1, double n2, Mode form)
    {
        mode = form;
        if (form == RECT)
         {
             x = n1;
             y = n2;
        }
        else if (form == POL)
        {
            double mag = n1; // 임시 지역 변수
            double ang = n2 / Rad_to_deg; // 각도를 라디안으로 변환
            x = mag * cos(ang);
            y = mag * sin(ang);
        }
        else
        {
             cout << "Vector()에 전달된 제 3의 매개변수가 잘못되었다.\n";
             cout << "그래서 벡터를 0으로 설정하였다.\n";
             x = y = 0.0;
             mode = RECT;
        }
    }

    Vector::~Vector()    // 파괴자
    {
    }

    void Vector::polar_mode()    // 극 좌표 모드로 설정한다
    {
        mode = POL;
    }

    void Vector::rect_mode()     // 직각 좌표 모드로 설정한다
    {
        mode = RECT;
    }

    // 연산자 오버로딩
    // 두 Vectors 객체를 더한다
    Vector Vector::operator+(const Vector & b) const
    {
        return Vector(x + b.x, y + b.y);
    }

    // Vector a에서 Vector b 객체를 뺀다 
    Vector Vector::operator-(const Vector & b) const
    {
        return Vector(x - b.x, y - b.y);
    }

    // vector 객체의 부호를 바꾼다
    Vector Vector::operator-() const
    {
        return Vector(-x, -y);
    }

    // vector 객체에 n을 곱한다
    Vector Vector::operator*(double n) const
    {
        return Vector(n * x, n * y);
    }

    // 프렌드 메서드들
    // n 에 Vector a를 곱한다
    Vector operator*(double n, const Vector & a)
    {
        return a * n;
    }

    // mode가 RECT이면 직각좌표를 출력한다.
    // mode가 POL이면 극좌표를 출력한다
    std::ostream & operator<<(std::ostream & os, const Vector & v)
    {
        if (v.mode == Vector::RECT)
             os << "(x,y) = (" << v.x << ", " << v.y << ")";
        else if (v.mode == Vector::POL)
        {
             os << "(m,a) = (" << v.magval() << ", "
                 << v.angval() * Rad_to_deg << ")";
        }
        else
             os << "Vector object mode is invalid";
        return os; 
    }

}  // end namespace VECTOR