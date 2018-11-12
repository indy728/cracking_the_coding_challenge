#include <iostream>
using namespace std;

string    pal_perm(string str);
char    is_upper(char c);
char    is_lower(char c);

int main() {
    string pal;
    cout << "Give me a string and I'll tell you if it can be a palindrome:" << endl;
    getline(cin, pal);
    cout << "The string is" << pal_perm(pal) << " a palindrome." << endl;
    return 0;
}

string    pal_perm(string str)
{
    int i, odds = 0, len = str.length();
    int arr[26] = {0};
    char c;

    if (len < 2) return " not";
    for (i = 0 ; i < len ; i++)
    {
        c = str[i];
        if (is_upper(c))
            c -= 'A' - 'a';
        if (is_lower(c))
            arr[c - 'a']++;

    }
    i = -1;
    while(++i < (26)) if (arr[i] % 2) odds++;
    return odds > 1 ? " not" : "";
}

char    is_upper(char c)
{
    return ('A' <= c  && c <= 'Z') ? 1 : 0;
}

char    is_lower(char c)
{
    return ('a' <= c && c <= 'z') ? 1 : 0;
}