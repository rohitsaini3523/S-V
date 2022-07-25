#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cout << "Orignal Data: ";
    getline(cin, s);
    int key;
    cout << "Key: ";
    cin >> key;
    for (int i = 0; i < s.length(); i++)
    {
        if(s[i]>96 && s[i]<123)
            s[i] = (s[i] + key - 'a') % 26 + 'a';
        else if (s[i] > 64 && s[i] < 91)
            s[i] = (s[i] + key - 'A') % 26 + 'A';
        else if (s[i] > 47 && s[i] < 58)
            s[i] = (s[i] + key - '0') % 10 + '0';
    }
    cout << "Encrypted Data: ";
    cout << s << "\n";
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] > 96 && s[i] < 123)
         {   s[i] -= 'a';
        s[i] = (s[i] - key) % 26;
        s[i] += 26 +'a';
        if(s[i] > 'z')
            s[i] -= 26;}
         else if (s[i] > 64 && s[i] < 91)
         {
             s[i] -= 'A';
             s[i] = (s[i] - key) % 26;
             s[i] += 26 + 'A';
             if (s[i] > 'Z')
                 s[i] -= 26;
         }
         else if (s[i] > 47 && s[i] < 58)
         {
             s[i] -= '0';
             s[i] = (s[i] - key) % 10;
             s[i] += 10 + '0';
             if (s[i] > '9')
                 s[i] -= 10;
         }
         // cout << s[i] << " ";
    }
    cout << "Decrypted Data: ";
    cout << s;
    return 0;
}