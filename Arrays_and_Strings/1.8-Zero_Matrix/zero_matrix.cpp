#include <iostream>
using namespace std;

//  It should be noted that the C code for this problem compiles and is more efficient than using 
//  the C++ string class

string  string_compression(string str);
int     get_compressed_length(string str, int len);
string  compress(string str, int len);
int     digits(int n);


int main()
{
    string extended;

    cout << "Give me a string that can be compressed the old way:" << endl;
    cin >> extended;
    cout << "The compressed version of the string is " << string_compression(extended) << endl;
    
    return 0;
}

string  string_compression(string str)
{
    int i = -1, len = str.length(), compressed;

    compressed = get_compressed_length(str, len);
    if (len > compressed) return compress(str, len);
    
    return (str);    
}

int     get_compressed_length(string str, int len)
{
    char c;
    int clen = 0, i = 0, n;

    while (str[i])
    {
        n = 0;
        c = str[i];
        if (i + 1 < len && str[i + 1] == c)
        {
            while (str[i] == c)
            {
                i++;
                n++;
            }
            clen += 1 + digits(n);
        }
        else
        {
            i++;
            clen += 2;
        }
    }
    return (clen);
}

string  compress(string str, int len)
{
    int i = 0, j = 0, counter;
    string compressed_string, counter_str;
    
    while (str[i])
    {
        counter = 1;
        compressed_string.push_back(str[i]);
        if (i + 1 < len && str[i + 1] == compressed_string[j])
        {    
            i++;
            while (str[i] == compressed_string[j])
            {
                counter++;
                i++;
            }
        }  
        else i++;
        j++;
        counter_str = to_string(counter);
        compressed_string.append(counter_str);
        j+= counter_str.length();
    }
    return (compressed_string);
}

int     digits(int n)
{
    int i = 0;

    while (n)
    {
        n /= 10;
        i++;
    }
    return (i);
}