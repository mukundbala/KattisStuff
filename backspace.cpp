#include <bits/stdc++.h>
using namespace std;

//max 106 size string, On will work

int main()
{
    deque <char> letters;
    string final;
    string inp; cin>>inp;
    int lettercnt=0;

    for (int i=0 ; i<inp.size();++i)
    {
        char inputLetter=inp[i];
        if (inputLetter=='<')
        {
            letters.pop_back();
            lettercnt-=1;
        }
        else
        {
            letters.push_back(inputLetter);
            lettercnt+=1;
        }
    }
    for (int i=0 ; i<lettercnt ; ++i)
    {
        final += letters[i];
    }
    cout << final << endl;
}