#include <iostream>
#include <string>
#include <math.h>

using namespace std;


bool isPalindrome(string s)
{
    bool res = true;
    for (int i = 0; i < round(s.length()/2); i++)
    {
        if (s[i] != s[s.length()-1-i])
        {
            res = false;
            break;
        }
    }
    return res;
}

void show_palindrome(bool r)
{
    if (r)
        cout << "it is a palindrome" <<endl;
    else
        cout << "it is not a palindrome" <<endl;
}

// Palindrome 회문 
int main()
{
    string one("Lottery Winner!");
    string two("otto");
    string three("ottotto");

    show_palindrome(isPalindrome(one));
    show_palindrome(isPalindrome(two));
    show_palindrome(isPalindrome(three));

    return 0;
}