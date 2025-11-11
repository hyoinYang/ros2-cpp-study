// workermi.h -- working classes with MI
#ifndef WORKERMI_H_
#define WORKERMI_H_

#include <string>
#include <random> 

class Person // Person 클래스
{
    private:
        std::string firstname;
        std::string lastname;

    protected:
        void Data() const;
        void Get(); 

    public:
        Person() : firstname("Yongwoo"), lastname("Park") {}
        Person(const std::string & s, const std::string & r)
        : firstname(s), lastname(r) {}

        virtual ~Person() = 0;
        virtual void Set() = 0; 
        virtual void Show() const; 
};

class Gunslinger : virtual public Person
{
    private:
        int notch;
        double gunTime;

    protected:
        void Get();
        void Data() const;

    public:
        Gunslinger() : Person(), notch(0), gunTime(1.0) {}
        Gunslinger(const std::string & s, const std::string & n, int p = 0, double k =1.0)
        : Person(s, n), notch(p), gunTime(k) {}
        Gunslinger(const Person & wk, int p = 0, double k = 1.0) 
        : Person(wk), notch(p), gunTime(k) {}

        void Set();
        void Show() const;
        double Draw() const; 
};

class PokerPlayer : virtual public Person
{
    protected:
        void Get();
        void Data() const;

    public:
        PokerPlayer() : Person() {}
        PokerPlayer(const std::string & s, const std::string & n)
        : Person(s, n){}
        PokerPlayer(const Person & wk)
        : Person(wk) {}

        void Set();
        void Show() const; 
        int Draw();
};

// multiple inheritance
class BadDude : public Gunslinger, public PokerPlayer
{
    protected:
        void Get();
        void Data() const;

    public:
        BadDude() {}
        BadDude(const std::string & s, const std::string & n, int p = 0, double y = 1.0)
        : Person(s,n), Gunslinger(s, n, p, y), PokerPlayer(s, n) {}
        BadDude(const Person & wk, int p = 0, double y = 1.0)
        : Person(wk), Gunslinger(wk,p, y), PokerPlayer(wk) {}

        void Set();
        void Show() const;
        double Gdraw() const;
        int Cdraw(); 
};

#endif