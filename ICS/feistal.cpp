#include<bits/stdc++.h>
using namespace std;

string keys[16];

int printRandoms(int lower, int upper)
{
    int num = (rand() % (upper - lower + 1)) + lower;
    return num;
}
string binary(string j)
{
    int value = 0;
    int k = j.length();
    int i = 0;
    while (i < k)
    {
        value += j[i] - 48;
        // cout << value << " " <<j[i] << "\n";
        value *= 10;
        i++;
    }
    value /= 10;
    // cout << value << "\n";
    //  program for integer to binary
    vector<int> ans;
    int k1 = 0;
    int n = value;
    while (n > 0)
    {
        k1 = (n % 2);
        n = n / 2;
        ans.push_back(k1);
    }
    if (ans.size() != 8)
    {
        // reverse(ans.begin(), ans.end());
        while (ans.size() != 8)
        {
            ans.push_back(0);
        }
    }
    string binary_converted = "";
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++)
    {
        binary_converted += to_string(ans[i]);
    }
    return binary_converted;
}

int decimal(string n)
{
    reverse(n.begin(), n.end());
    int ans = 0;
    for (int i = 0; i < n.length(); i++)
    {
        if (n[i] == '1')
            ans += pow(2, i);
    }
    // cout << "Ans " << ans << "\n";
    return ans%128;
}
string divide(string binary_converted)
{
    string l1 = "";
    string r1 = "";
    for (int i = 0; i < 4; i++)
    l1.push_back(binary_converted[i]);
    for (int i = 4; i < 8; i++)
    r1.push_back(binary_converted[i]);
    // cout << l1 << " " << r1 << "\n";
    return l1 + ' ' + r1;
}

string divide_key(string binary_converted)
{
    string r1 = "";
    for (int i = 4; i < 8; i++)
    r1.push_back(binary_converted[i]);
    // cout << l1 << " " << r1 << "\n";
    return r1;
}

string XOR(string s1, string s2 )
{
    string s3 ="0000";
    for (int i = 0; i < 4; i++)
    {
        s3[i] = (48 + ((s1[i] - 48) ^ (s2[i] - 48)));
    }
    return s3;
}

string get_cipher_text(string s)
{
    string ans = divide(binary(s));
    string f="";
    string l1 = ans.substr(0, 4);
    string r1 = ans.substr(5, 4);
    string l2, r2;
    // cout << l1 << " " << r1;
    for (int i = 0; i < 16; i++)
    {
        l2 = r1;
        f = XOR(keys[i], r1);
        r2 = XOR(f, l1);
        l1 = r2;
        r1 = l2;
    }
    // cout << l1 << r1 << "\n";
    return l1+r1;

}

string decrypte(string s)
{
    string ans = divide(binary(s));
    // cout << ans << "\n";
    string f = "";
    string l1 = ans.substr(0, 4);
    string r1 = ans.substr(5, 4);
    string l2, r2;
    // swap(l1, r1);
    // cout << l1 << " " << r1;
    for (int i = 15; i >= 0; i--)
    {
        l2 = r1;
        f = XOR(keys[i], r1);
        r2 = XOR(f, l1);
        l1 = r2;
        r1 = l2;
    }
    // cout << l1 << r1 << "\n";
    return l1 + r1;
}

int main()
{
    string temp;
    for (int i = 0; i < 16; i++)
    {
        temp = divide_key(binary(to_string(printRandoms(1, 31))));
        keys[i] = temp;
    }
    string input;
    cout << "Enter Plain Text: ";
    getline(cin, input);
    // cout << "Keys:\n";
    // for (int i = 0; i < 16; i++)
    // {
    //     cout <<" Key "<<i+1<<" -> " <<keys[i] << "\n";
    // }
    string ans="";
    string temp_store;
    string cipher_text ="";
    for (int i = 0; i < input.length(); i++)
    {
        temp_store = get_cipher_text(to_string(input[i]));
        // reverse(temp_store.begin(), temp_store.end());
        cipher_text += (char)decimal(temp_store);
    }
    // cout << (int)cipher_text[0] << "\n";
    // XOR("1000", "0100");
    cout << "(Encrypted)Cipher Text: ";
    cout << cipher_text << "\n";
    // cout << "Cipher text length: " << cipher_text.length()<<"\n";
    cout << "Decrypted: ";
    for (int i = 0; i < cipher_text.length(); i++)
        ans += (char)decimal(decrypte(to_string(cipher_text[i])));
    cout << ans << "\n";
    return 0;
}