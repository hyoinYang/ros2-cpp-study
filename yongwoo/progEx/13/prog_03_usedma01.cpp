// use_dma.cpp -- polymorphic testing with ABC
#include <iostream>
#include <string>
#include "prog_03_dma.h"

using namespace std;

const int MAX_OBJECTS = 3; // Reduced for simpler testing

int main()
{
    ABC_dma * p_objects[MAX_OBJECTS]; // Array of pointers to the ABC
    char temp_label[80];
    int temp_rating;
    char kind;

    for (int i = 0; i < MAX_OBJECTS; i++)
    {
        cout << "\n--- Object " << i + 1 << " ---\n";
        cout << "Enter object label: ";
        cin.getline(temp_label, 80);
        
        cout << "Enter object rating: ";
        // A simple way to handle potential input errors
        while (!(cin >> temp_rating))
        {
            cin.clear();
            while (cin.get() != '\n')
                continue;
            cout << "Invalid rating. Enter an integer rating: ";
        }

        cout << "Enter 1 for lacksDMA (Color) or "
             << "2 for hasDMA (Style): ";
        while (cin >> kind && (kind != '1' && kind != '2'))
            cout <<"Enter either 1 or 2: ";

        if (kind == '1')
        {
            char temp_color[40];
            cout << "Enter color: ";
            // Consume the rest of the line before getting the color string
            cin.get(); 
            cin.getline(temp_color, 40);
            
            p_objects[i] = new lacksDMA(temp_color, temp_label, temp_rating);
        }
        else // kind == '2'
        {
            char temp_style[80];
            cout << "Enter style: ";
            // Consume the rest of the line before getting the style string
            cin.get();
            cin.getline(temp_style, 80);
            
            p_objects[i] = new hasDMA(temp_style, temp_label, temp_rating);
        }
        
        // Consume the rest of the line before the next loop iteration
        while (cin.get() != '\n')
            continue;
    }

    cout << "\n==================================\n";
    cout << "Displaying all created objects:\n";
    cout << "==================================\n";

    for (int i = 0; i < MAX_OBJECTS; i++)
    {
        // Polymorphic call: The correct View() method is called 
        // based on the actual object type at runtime.
        p_objects[i]->View(); 
        cout << endl;
    }
            
    // Clean up dynamic memory
    for (int i = 0; i < MAX_OBJECTS; i++)
    {
        delete p_objects[i]; // Virtual destructor ensures correct object cleanup
    }

    cout << "Done.\n";
    return 0;    
}