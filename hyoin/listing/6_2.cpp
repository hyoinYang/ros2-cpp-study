#include <iostream>

using namespace std;

int main(){
    char ch;

    cout << "please typing. \n";
    cin.get(ch);

    while(ch != '.'){
        if (ch == '\n') cout << ch;
        else cout << ++ch;

        cin.get(ch);
    }

    cout << "\nsorry to confusion.\n";

    return 0;

}