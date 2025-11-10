#include "cd.h"

class Classic : public Cd
{
    private:
        char title[50];

    public:
        void Report() const;
        Classic();
        Classic(char * t, char * sl , char * s2 , int n , double x);
        ~Classic();
        Classic & operator=(const Classic & d);
};