// dma.h  -- inheritance and dynamic memory allocation
#ifndef DMA_H_
#define DMA_H_
#include <iostream>


// ABC
class ABC_dma
{
public:
    virtual void View() const = 0;
    virtual ~ABC_dma(){}

};


//  Base Class Using DMA, derived from ABC_dma
class baseDMA : public ABC_dma
{
private:
    char * label;
    int rating;
    
public:
    baseDMA(const char * l = "null", int r = 0); // l -> label, r-> rating
    baseDMA(const baseDMA & rs); // copy
    virtual ~baseDMA(); // 소멸자는 virtual과 함께 선언 (파생 소멸자와 같이 사라짐)
    baseDMA & operator=(const baseDMA & rs); // opeartor "=" 을 오버로딩
    friend std::ostream & operator<<(std::ostream & os, 
                                     const baseDMA & rs); // 프렌드함수 : 객체가 오른편에 위치
    
    virtual void View() const; //override ABC_dma's
};

// derived class without DMA
// no destructor needed
// uses implicit copy constructor
// uses implicit assignment operator
class lacksDMA :public baseDMA
{
private:
    enum { COL_LEN = 40};
    char color[COL_LEN];
public:
    //constructor : color, label, rating 초기화
    lacksDMA(const char * c = "blank", const char * l = "null",
              int r = 0);
    lacksDMA(const char * c, const baseDMA & rs);
    friend std::ostream & operator<<(std::ostream & os, 
                                     const lacksDMA & rs);
    virtual void View() const;
};

// derived class with DMA
class hasDMA :public baseDMA
{
private:
    char * style;
public:
    hasDMA(const char * s = "none", const char * l = "null",
              int r = 0);
    hasDMA(const char * s, const baseDMA & rs);
    hasDMA(const hasDMA & hs);
    virtual ~hasDMA();
    hasDMA & operator=(const hasDMA & rs);  
    friend std::ostream & operator<<(std::ostream & os, 
                                     const hasDMA & rs);
    virtual void View() const;
};

#endif
