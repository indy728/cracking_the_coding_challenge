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
