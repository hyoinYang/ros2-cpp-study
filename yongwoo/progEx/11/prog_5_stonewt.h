// stonewt.h -- definition for the Stonewt class
#ifndef STONEWT_H_
#define STONEWT_H_
#include <iostream>

class Stonewt
{
private:
    enum Mode {STONE, INT_POUND, DOUBLE_POUND};
    Mode state; 

    enum {Lbs_per_stn = 14};      // pounds per stone
    int stone;                    // whole stones
    double pds_left;              // fractional pounds
    double pounds;                // entire weight in pounds


public:
    friend std::ostream & operator<<(std::ostream & os, const Stonewt & st);
    
    void set_stone_mode() { state = STONE; }
    void set_int_pound_mode() { state = INT_POUND; }
    void set_double_pound_mode() { state = DOUBLE_POUND; }
    
    Stonewt operator+(const Stonewt & st) const;
    Stonewt operator-(const Stonewt & st) const;
    Stonewt operator*(double mult) const; // Stonewt * double

    Stonewt(double lbs);          // constructor for double pounds
    Stonewt(int stn, double lbs); // constructor for stone, lbs
    Stonewt(int lbs);
    Stonewt();                    // default constructor
    ~Stonewt();
    
};

#endif