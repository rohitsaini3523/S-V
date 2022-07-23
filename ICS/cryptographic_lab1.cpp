#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cout << "Orignal Data: ";
    cin >> s;
    int key;
    cout << "Key: ";
    cin >> key;
    for (int i = 0; i < s.length(); i++)
    {
        s[i] -= 97;
        s[i] = (s[i] + key) % 26 + 97;
    }
    cout << "Encrypted Data: ";
    cout << s << "\n";
    for (int i = 0; i < s.length(); i++)
    {
        s[i] -= 97;
        s[i] = (s[i] - key) % 26 + 97;
    }
    cout << "Decrypted Data: ";
    cout << s;
    return 0;
}