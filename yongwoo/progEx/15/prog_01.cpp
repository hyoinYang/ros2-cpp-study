// tv.cpp -- methods for the Tv class (Remote methods are inline)
#include <iostream>
#include "prog_01.h"

bool Tv::volup()
{
    if (volume < MaxVal)
    {
        volume++;
        return true;
    }
    else
        return false;
}

bool Tv::voldown()
{
    if (volume > MinVal)
    {
        volume--;
        return true;
    }
    else
        return false;
}

void Tv::chanup()
{
    if (channel < maxchannel)
        channel++;
    else
        channel = 1;
}

void Tv::chandown()
{
    if (channel > 1)
        channel--;
    else
        channel = maxchannel;
}

void Tv::settings() const
{
    using std::cout;
    using std::endl;

    cout << "TV is " << (state == Off? "Off" : "On") << endl;

    if (state == On)
    {
        cout << "Volume setting = " << volume << endl;
        cout << "Channel setting = " << channel << endl;
        cout << "Mode = "
            << (mode == Antenna? "antenna" : "cable") << endl;
        cout << "Input = "
            << (input == TV? "TV" : "DVD") << endl;
    }
}

void Remote::show_dmode() const
{
    using std::cout;
    using std::endl;

    cout << "Remote is on " << (dialog_mode == DIA?"dialog":"general") << " mode." << endl;

}

void Tv::switch_dmode(Remote &r)
{
    using std::cout;
    using std::endl;
    if (state == On)
    {
        if (r.dialog_mode == r.DIA)
        {
            r.dialog_mode = r.GEN;
            cout << "Changed the remote mode : Dialog mode -> General mode" << endl;
        }
        else
        {
            r.dialog_mode = r.DIA;
            cout << "Changed the remote mode : General mode -> Dialog mode" << endl;
        }
    }
    else
    {
        cout << "Tv is off. Please turn on TV if you want to switch the remote mode" << endl;
    }
}