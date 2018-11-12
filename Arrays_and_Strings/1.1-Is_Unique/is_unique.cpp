#include <iostream>
#include <regex>
using namespace std;

string is_unique(string str);

// This is my first cpp program. It might be hacky but I'm learning
// and it works. It's essentially copy paste hash table solution
// from  C.

int main() {
    string user_input;
    
    cout << "Give me a word and I'll tell you if it has duplicate letters:" << endl;
    cin >> user_input;
    cout << "The characters in the string you entered are" << is_unique(user_input) << " all unique.\n";
    return 0;
}

string is_unique(string str)
{
    char arr[127-32] = {0};
    int i = -1;
    char x;
    
    while (str[++i])
    {
        x = str[i] - 32;
        arr[x]++;
        if (arr[x] > 1)
            return " not";
    };
    return "";
}