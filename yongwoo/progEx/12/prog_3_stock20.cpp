// stock20.cpp -- augmented version
#include <iostream>
#include "prog_3_stock20.h"
#include <cstring>
using namespace std;

const int STKS = 4;
int main()
{

// create an array of initialized objects
    Stock stocks[STKS] = {
        Stock("NanoSmart", 12, 20.0),
        Stock("Boffo Objects", 200, 2.0),
        Stock("Monolithic Obelisks", 130, 3.25),
        Stock("Fleep Enterprises", 60, 6.5)
        };

    std::cout << "Stock holdings:\n";

    int st;
    for (st = 0; st < STKS; st++)
        cout << stocks[st];

// set pointer to first element
    const Stock * top = &stocks[0];

    for (st = 1; st < STKS; st++)
        top = &top->topval(stocks[st]);

// now top points to the most valuable holding
    std::cout << "\nMost valuable holding:\n";
	std::cout << *top << endl;
    // std::cin.get();
    return 0; 
}

void Stock::set_company(const char *co)
{
    if (co==nullptr)
    {
        company = new char[1];
        company[0] = '\0';
        return;
    }
    size_t len = strlen(co);
    company = new char[len+1];
    strcpy(company, co);
}

// constructors
Stock::Stock()        // default constructor
{
    set_company("no name");
    shares = 0;
    share_val = 0.0;
    total_val = 0.0;
}

Stock::Stock(const char *co, long n, double pr)
{
    set_company(co);
    if (n < 0)
    {
        std::cout << "Number of shares can't be negative; "
                   << company << " shares set to 0.\n";
        shares = 0;
    }
    else
        shares = n;

    share_val = pr;
    set_tot();
}

// class destructor
Stock::~Stock()        // quiet class destructor
{
    delete [] company;
}

// deep copy
Stock::Stock(const Stock &s)
    :shares(s.shares), share_val(s.share_val), total_val(s.total_val)
{
    size_t len = strlen(s.company);
    company = new char[len+1];
    strcpy(company, s.company);
}

Stock &Stock::operator=(const Stock &s)
{
    if (this == &s)
        return *this; //자기자신을 대입 할 경우
    
    delete [] company;

    size_t len = strlen(s.company);
    company = new char[len+1];
    strcpy(company, s.company);

    shares = s.shares;
    share_val = s.share_val;
    total_val = s.total_val;

    return *this;
}

// other methods
void Stock::buy(long num, double price)
{
     if (num < 0)
    {
        cout << "Number of shares purchased can't be negative. "
             << "Transaction is aborted.\n";
    }
    else
    {
        shares += num;
        share_val = price;
        set_tot();
    }
}

void Stock::sell(long num, double price)
{
    using std::cout;
    if (num < 0)
    {
        cout << "Number of shares sold can't be negative. "
             << "Transaction is aborted.\n";
    }
    else if (num > shares)
    {
        cout << "You can't sell more than you have! "
             << "Transaction is aborted.\n";
    }
    else
    {
        shares -= num;
        share_val = price;
        set_tot();
    }
}

void Stock::update(double price)
{
    share_val = price;
    set_tot();
}

const Stock & Stock::topval(const Stock & s) const
{
    if (s.total_val > total_val)
        return s;
    else
        return *this; 
}

ostream &operator<<(std::ostream &os, const Stock &st)
{
    using std::ios_base;
    ios_base::fmtflags orig = os.setf(ios_base::fixed, ios_base::floatfield);
    std::streamsize prec = os.precision(3);

    os <<"Company: " <<st.company << endl;
    os <<"Shares: " << st.shares << endl;
    os << "Share Price: $" << st.share_val << endl;
    os.precision(2);
    os << "Total Worth: $" << st.total_val << endl;

    os.setf(orig, ios_base::floatfield);
    os.precision(prec);

    return os;
}

// void Stock::show() const
// {
//     using std::cout;
//     using std::ios_base;
//     // set format to #.###
//     ios_base::fmtflags orig = 
//         cout.setf(ios_base::fixed, ios_base::floatfield); 
//     std::streamsize prec = cout.precision(3);

//     cout << "Company: " << company
//         << "  Shares: " << shares << '\n';
//     cout << "  Share Price: $" << share_val;
//     // set format to #.##
//     cout.precision(2);
//     cout << "  Total Worth: $" << total_val << '\n';

//     // restore original format
//     cout.setf(orig, ios_base::floatfield);
//     cout.precision(prec);
// }


