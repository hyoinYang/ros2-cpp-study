// 기초클래스
class Cd // CD 디스크를 나타낸다
{
private:
    char performers[50];
    char label[20];
    int selections;
    double playtime;

public:
    Cd(char * sl , char * s2 , int n , double x);
    Cd(const Cd & d);
    Cd();
    ~Cd();
    virtual void Report() const; // CD의 모든 데이터를 보고한다
    Cd & operator=(const Cd & d);

};