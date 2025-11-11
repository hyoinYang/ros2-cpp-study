#include <iostream>
#include <cstring>
#include "workmi.h"
#include "QueueT.h"

const int SIZE = 5;
char choice;
int main()
{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::strchr;

    QueueTp<Worker*> staff( SIZE );

    int ct;
    for (ct = 0; ct < SIZE; ct++)
    {
        cout << "Enter the employee category:\n"
            << "w: waiter  s: singer  t: singing waiter  q: quit\n";
        cin >> choice;
        while (strchr("wstq", choice) == NULL)
        {
            cout << "Please enter a w, s, t, or q: ";
            cin >> choice;
        }
        if (choice == 'q')
            break;

        Worker* temp;

        switch(choice)
        {
            case 'w': temp = new Waiter; break;
            case 's': temp = new Singer; break;
            case 't': temp = new SingingWaiter; break;
        }

        cin.get();
        temp->Set();

        if (!staff.enqueue(temp))
        {
            cout << "Queue full — cannot add more employees.\n";
            delete temp;
            break;
        }
    }
    if (choice != 'q')
        cout << "\nHere is your staff:\n";
    Worker* w;

    while (!staff.isempty())
    {
        staff.dequeue(w);
        cout << endl;
        w->Show();
        delete w;
    }

    cout << "\nBye.\n";
    return 0;
}
