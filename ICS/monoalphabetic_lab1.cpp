#include <iostream>
#include<algorithm>
#include<vector>
#include<random>
#include<chrono>
using namespace std;
 
int main() 
{
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    default_random_engine e(seed);
    vector<char> alphabet, key;
    for (int i = 0; i < 26; i++)
    {
        alphabet.push_back( i + 'a');
        key.push_back(i + 'a');
    }
    shuffle(key.begin(), key.end(), e);
    string s;
    cout << "Enter Text: ";
    getline(cin, s);
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] > 96 && s[i] < 123)
            s[i] = key[s[i] - 'a'];
    }
    cout << "Encrypted text: " << s << "\n";
    for (int i = 0; i < s.length(); i++)
    {
        s[i] = alphabet[find(key.begin(), key.end(), s[i])-key.begin()];
    }
    cout << "Decrypted text: " << s << "\n";

    return 0;
}