/*

16장 프로그래밍 연습문제 3

단어들을 파일로부터 얻도록 해 코드를 수정하라.
한 가지 방법은, string 배열 대신 vector<string> 객체를 사용하는 것이다. 그렇게 하면 push_back()을 사용해 파일에 있는 많은 단어들을 vector<string> 객체에 복사할 수 있다.
그리고 size() 멤버를 사용하여 단어 목록의 길이를 결정할 수 있다.

프로그램은 파일로부터 한 번에 한 단어씩 읽어야 하기 때문에, getline() 보다는 >> 연산자를 사용해야 한다.
파일에 들어있는 단어들은 빈칸, 탭, 개행에 의해 분리되어 있어야 한다.

*/
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <vector>
using std::string;
std::vector<string> wordlist;

int main()
{
    using std::cout;
    using std::cin;
    using std::tolower;
    using std::endl;
    
    std::ifstream fin("../words.txt");

    if (!fin)
    {
        cout << "[ERROR] Can't open file" << endl;
        return 1;
    }
    string word;
    while (fin >> word)
    {
        wordlist.push_back(word);
    }

    fin.close();

    for (string w : wordlist)
    {
        cout << w << "\n";
    }

    std::srand(std::time(0));
    char play;
    cout << "Will you play a word game? <y/n> ";
    cin >> play;
    play = tolower(play);
    while (play == 'y')
    {
        string target = wordlist[std::rand() % wordlist.size()];
        int length = target.length();
        string attempt(length, '-');
        string badchars;
        int guesses = 6;
        cout << "Guess my secret word. It has " << length
            << " letters, and you guess\n"
            << "one letter at a time. You get " << guesses
            << " wrong guesses.\n";
        cout << "Your word: " << attempt << endl;
        while (guesses > 0 && attempt != target)
        {
            char letter;
            cout << "Guess a letter: ";
            cin >> letter;
            if (badchars.find(letter) != string::npos
                || attempt.find(letter) != string::npos)
            {
                cout << "You already guessed that. Try again.\n";
                    continue;
            }
            int loc = target.find(letter);
            if (loc == string::npos)
            {
                cout << "Oh, bad guess!\n";
                --guesses;
                badchars += letter; // add to string
            }
            else
            {
                cout << "Good guess!\n";
                attempt[loc]=letter;
                // check if letter appears again
                loc = target.find(letter, loc + 1);
                while (loc != string::npos)
                {
                    attempt[loc]=letter;
                    loc = target.find(letter, loc + 1);
                }
           }
            cout << "Your word: " << attempt << endl;
            if (attempt != target)
            {
                if (badchars.length() > 0)
                    cout << "Bad choices: " << badchars << endl;
                cout << guesses << " bad guesses left\n";
            }
        }
        if (guesses > 0)
            cout << "That's right!\n";
        else
            cout << "Sorry, the word is " << target << ".\n";

        cout << "Will you play another? <y/n> ";
        cin >> play;
        play = tolower(play);
    }

    cout << "Bye\n";

    return 0; 
}