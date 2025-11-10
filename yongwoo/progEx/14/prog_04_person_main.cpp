#include <iostream>
#include <cstring>
#include "prog_04_person.h"
const int SIZE = 3;

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::strchr;

    Person * lolas[SIZE];

    int ct;
    for (ct = 0; ct < SIZE; ct++)
    {
        char choice;
        cout << "Enter the person category:\n"
        << "g: gunslinger, p: poker player, "
        << "b: bad dude, q: quit\n";

        cin >> choice;
        // 수정된 선택 문자열 "gpbq"
        while (strchr("gpbq", choice) == NULL) 
        {
            cout << "Please enter a g, p, b or q: ";
            cin >> choice;
        }

        if (choice == 'q')
            break;

        switch(choice)
        {
            case 'g': lolas[ct] = new Gunslinger;
            break;
            case 'p': lolas[ct] = new PokerPlayer;
            break;
            case 'b': lolas[ct] = new BadDude;
            break;
        }

        cin.get(); 
        lolas[ct]->Set();
    }

    cout << "\nHere is your staff:\n";

    int i;

    for (i = 0; i < ct; i++)
    {
        cout << endl;
        lolas[i]->Show();
    }

    for (i = 0; i < ct; i++)
       delete lolas[i];

    cout << "Bye.\n";

    return 0; 
}