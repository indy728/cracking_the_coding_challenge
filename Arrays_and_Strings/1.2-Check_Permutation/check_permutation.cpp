#include <iostream>
#include <regex>
using namespace std;

string    check_permutation(string s1, string s2);
char    checksum(int *arr, int range);

// This is my first cpp program. It might be hacky but I'm learning
// and it works. It's essentially copy paste hash table solution
// from  C.

int main() {
    string s1, s2;
    
    cout << "Give me 2 words and I'll tell you if they are permutations:" << endl;
    cin >> s1;
    cin >> s2;
    cout << "The characters in the string you entered are" << check_permutation(s1, s2) << " permutations.\n";
    return 0;
}

string    check_permutation(string s1, string s2)
{
    int arr[127-32] = {0};
    int i = 0;
    char x, y;

    while(s1[i] && s2[i])
    {
        x = s1[i] - 32;
        y = s2[i] - 32;
        arr[x]++;
        arr[y]--;
        i++;
    }

    if (s1[i] || s2[i] || checksum(arr, 127 - 32))
        return " not";
    return "";
}

char    checksum(int *arr, int range)
{
    int sum = 0;

    for (int i = 0; i < range; i++)
    {
        sum += arr[i];
    }

    return sum == 0 ? 0 : 1;
}