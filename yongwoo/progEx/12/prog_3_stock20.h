// stock20.h -- augmented version
#ifndef STOCK20_H_
#define STOCK20_H_
// #include <string>
#include <iostream>

class Stock
{
private:

    // std::string company;
    char *company;
    int shares;
    double share_val;
    double total_val;
    void set_tot() { total_val = shares * share_val; }
    void set_company(const char *co);

public:

    Stock();        // default constructor
    // Stock(const std::string & co, long n = 0, double pr = 0.0);
    Stock(const char *co, long n = 0, double pr =0.0);

    Stock(const Stock &s); // deep copy
    Stock &operator=(const Stock &s);

    ~Stock();       // do-nothing destructor

    void buy(long num, double price);
    void sell(long num, double price);
    void update(double price);

    // void show()const;
    friend std::ostream & operator<<(std::ostream & os, const Stock & st);

    const Stock & topval(const Stock & s) const;
};

#endif
