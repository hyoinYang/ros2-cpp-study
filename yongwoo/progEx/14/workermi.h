// workermi.h  -- working classes with MI
#ifndef WORKERMI_H_
#define WORKERMI_H_

#include <string>

class Person   // an abstract base class
{
private:
    std::string firstname;
    std::string lastname;
protected:
    virtual void Data() const;
    virtual void Get();
public:
    Person() : firstname("Yongwoo"), lastname("Park") {}
    Person(const std::string & s, const std::string & r)
            : firstname(s), lastname(r) {}
    virtual ~Person() = 0; // pure virtual function
    virtual void Set() = 0;
    virtual void Show() const;
};

class Gunslinger : virtual public Person
{
private:
    int notch;
    double Draw() const;
protected:
    void Get();
public:
    Gunslinger() : Person(), notch(0) {}
    Gunslinger(const std::string & s, const std::string & n, int p = 0)
            : Person(s, n), notch(p) {}
    Gunslinger(const Person & wk, int p = 0) 
            : Person(wk), notch(p) {} // 컴파일러가 알아서 복사생성자를 만들어줌
    void Set();
    void Show() const;
};

class PokerPlayer : virtual public Person
{
private:
    int Draw();
protected:
    void Get();
public:
    PokerPlayer() : Person() {}
    PokerPlayer(const std::string & s, const std::string & n)
            : Worker(s, n){}
    PokerPlayer(const Person & wk)
            : Worker(wk) {}
    void Set();
    void Show() const;
};

// multiple inheritance
class BadDude : public Gunslinger, public PokerPlayer
{
protected:
    void Get();
public:
    BadDude()  {}
    BadDude(const std::string & s, const std::string & n, int p = 0)
            : Person(s,n), Gunslinger(s, n, p), PokerPlayer(s, n) {}
    BadDude(const Person & wk, int p = 0)
            : Person(wk), Gunslinger(wk,p), PokerPlayer(wk) {}
    void Set();
    void Show() const;
    double Gdraw();
    int Cdraw(); 
};

#endif
