#include "cow.h"
#include <cstring>
#include <iostream>

namespace COW
{
    Cow::Cow()
    {
        name[0] = '\0';
        hobby = nullptr;
        weight = 0;
        
    }

    Cow::Cow(const char * nm, const char * ho, double wt)
    {
        strcpy(name, nm);

        hobby = new char[strlen(ho) + 1];
        strcpy(hobby, ho);
        
        weight = wt;
    }

    Cow::Cow(const Cow & c)
    {
        strcpy(name, c.name);

        hobby = new char[strlen(c.hobby) + 1];
        strcpy(hobby, c.hobby);
        
        weight = c.weight;
    }

    Cow::~Cow()
    {
        std::cout << "[소멸자 호출] Cow "
                    << (name[0] ? name : "(이름 없음)") 
                    << " 메모리 해제"
                    << ", 메모리 주소: " << static_cast<void*>(hobby)
                    << std::endl;

        delete [] hobby;
    }

    Cow & Cow::operator= (const Cow & c)
    {
        if (this == &c) return *this;

        delete [] hobby;

        strcpy(name, c.name);
        
        hobby = new char[strlen(c.hobby) + 1];
        strcpy(hobby, c.hobby);

        weight = c.weight;

        return *this;
    }


    void Cow::ShowCow() const
    {
        std::cout << " --- Cow Info Start --- " << "\n";

        std::cout << "Cow name: " << name << "\n";

        if (hobby)
            std::cout << "Cow hobby: " << hobby << "\n";
        else
            std::cout << "Cow hobby: (none)\n";

        if(weight == 0)
            std::cout << "Cow weight: (not set)" << "\n";
        else
            std::cout << "Cow weight: " << weight << "\n"; 
        
        std::cout << " --- Cow Info End --- " << "\n";
    }

}
