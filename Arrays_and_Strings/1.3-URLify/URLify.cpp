#include <iostream>
#include <regex>
using namespace std;

string urlify(string str);
int     url_strlen(string str);
char    is_whitespace(char c);

int main() {
    string url;
    cout << "Give me a string with a bunch of white space and I'll turn it into a url search string:" << endl;
    getline(cin, url);
    cout << "The url is: " << urlify(url) << endl;
    return 0;
}

string  urlify(string str)
{
    int i = 0, len = 0, url_len = url_strlen(str);
    string url;

    while (is_whitespace(str[i]))
        i++;
    while(str[i] && len < url_len)
    {
        if (is_whitespace(str[i]))
        {
            len += 3;
            url.append("\%20");
            while (is_whitespace(str[i]))
                i++;
            if (!str[i])
                len -= 3;
        }
        else
        {
            url.append(str, i, 1);
            ++i;
            ++len;
        }
    }
    return url;

}

int    url_strlen(string str)
{
    int i = 0, len = 0;

    while (is_whitespace(str[i]))
        i++;
    while(str[i])
    {
        if (is_whitespace(str[i]))
        {
            len += 3;
            while (is_whitespace(str[i]))
                i++;
            if (!str[i])
                len -= 3;
        }
        else
        {
            ++i;
            ++len;
        }
    }
    return len;
}

char    is_whitespace(char c)
{
    return c == ' ' || c == '\t' ? 1 : 0;
}