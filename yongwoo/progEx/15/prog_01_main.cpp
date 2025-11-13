#include <iostream>
#include "prog_01.h"

int main()
{
    using std::cout;
    
    Tv s42;
    cout << "Initial settings for 42\" TV:\n";
    s42.settings();

    Remote grey;
    grey.show_dmode();
    cout << "Trying Switching mode....\n";
    s42.switch_dmode(grey);
    grey.show_dmode();
    cout << "\n\n";

    s42.onoff();
    cout << "TV is On\n";
    grey.show_dmode();
    cout << "Trying Switching mode....\n";
    s42.switch_dmode(grey);
    grey.show_dmode();

    return 0;
}