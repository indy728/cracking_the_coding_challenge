#include <iostream>
using namespace std;

string    one_away(string s1, string s2);
char    replace_letter(string s1, string s2);
char    one_short(string s1, string s2);
int     lstrcmp(string s1, string s2);

int main() {
    string s1, s2;
    cout << "Give me 2 strings and I'll tell you if they are one character or fewer away:" << endl;
    cin >> s1;
    cin >> s2;
    cout << "The two strings provided are" << one_away(s1, s2) << " one or fewer modifications separated." << endl;
    return 0;
}

string    one_away(string s1, string s2)
{
    int l1 = s1.length(), l2 = s2.length();

    if (l1 == l2 && (!s1.compare(s2) || replace_letter(s1, s2)))
        return "";
    if (l1 == l2 + 1 && one_short(s2, s1))
        return "";
    if (l1 == l2 - 1 && one_short(s1, s2))
        return "";
    return " not";
}

char    replace_letter(string s1, string s2)
{
    int i = lstrcmp(s1, s2);

    s1[i] = s2[i];
    return (s1.compare(s2) ? 0 : 1);
}

char    one_short(string s1, string s2)
{
    int i = lstrcmp(s1, s2);

    return (s1.substr(i).compare(s2.substr(i + 1)) ? 0 : 1);
}

int     lstrcmp(string s1, string s2)
{
    int i = 0;

    while (s1[i] == s2[i]) i++;
    return i;
}