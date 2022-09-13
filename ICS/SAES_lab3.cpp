#include <bits/stdc++.h>
using namespace std;

int printRandoms(int lower, int upper)
{
    srand(time(0));
    int num = (rand() % (upper - lower + 1)) + lower;
    return num;
}

string generate_key(string key)
{
    char hex[16] = {'0','1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    key = "";
    for (int i = 0; i < 4; i++)
        key.push_back(hex[printRandoms(0, 31) * (i + 1) % 16]);
    return key;
}

string XOR(string s1, string s2)
{
    string s3;
    int k = 0;
    while (k < s1.size())
    {
        s3.push_back('0');
        k++;
    }
    for (int i = 0; i < k; i++)
    {
        s3[i] = (48 + ((s1[i] - 48) ^ (s2[i] - 48)));
    }
    return s3;
}

string RotNib(string s)
{
    string s1 = s.substr(0, 4);
    string s2 = s.substr(4, 4);
    s = s2 + s1;
    return s;
}

int to_decimal(string n)
{
    reverse(n.begin(), n.end());
    int ans = 0;
    for (int i = 0; i < n.length(); i++)
    {
        if (n[i] == '1')
            ans += pow(2, i);
    }
    // cout << "Ans " << ans << "\n";
    return ans % 255;
}

string convert_hex_to_binary(string key, int k)
{
    int decimal = 0;
    reverse(key.begin(), key.end());
    for (int i = 0; i < key.size(); i++)
    {
        if (key[i] >= 48 && key[i] < 58)
        {
            decimal += pow(16, i) * ((int)key[i] - 48);
        }
        if (key[i] >= 65 && key[i] < 71)
        {
            decimal += pow(16, i) * ((int)key[i] - 65 + 10);
        }
    }
    int ans = decimal;
    int i = 0;
    string binary = "";
    while (decimal > 0)
    {
        binary.push_back(decimal % 2 + 48);
        decimal = decimal / 2;
        i++;
    }
    if (k == 1)
        while (i < 16)
        {
            binary.push_back('0');
            i++;
        }
    else if (k == 2)
        while (i < 8)
        {
            binary.push_back('0');
            i++;
        }
    else
        while (i < 4)
        {
            binary.push_back('0');
            i++;
        }
    reverse(binary.begin(), binary.end());
    return binary;
}

string rcon(int n)
{
    if (n == 1)
        return "10000000";
    if (n == 2)
        return "00110000";
    return 0;
}

string convert_to_hex(int n)
{
    if (n == 1)
        return "1";
    if (n == 2)
        return "2";
    if (n == 3)
        return "3";
    if (n == 4)
        return "4";
    if (n == 5)
        return "5";
    if (n == 6)
        return "6";
    if (n == 7)
        return "7";
    if (n == 8)
        return "8";
    if (n == 9)
        return "9";
    if (n == 10)
        return "A";
    if (n == 11)
        return "B";
    if (n == 12)
        return "C";
    if (n == 13)
        return "D";
    if (n == 14)
        return "E";
    if (n == 15)
        return "F";
    return 0;
}

string SubNib(string s, int k)
{
    char a[4][4] = {{'9', '4', 'A', 'B'}, {'D', '1', '8', '5'}, {'6', '2', '0', '3'}, {'C', 'E', 'F', '7'}};
    string s1_1;
    string s1_2;
    string temp;
    for (int i = 0; i < s.size();)
    {
        s1_1 = s.substr(i, 2);
        i += 2;
        s1_2 = s.substr(i, 2);
        temp += a[to_decimal(s1_1)][to_decimal(s1_2)];
        // cout << "\n"<<to_decimal(s1_1) <<"--"<< to_decimal(s1_2)
        //      << "\n";
        i += 2;
        // cout << temp << "->";
    }
    return convert_hex_to_binary(temp, k);
    // incomplete
}

string ISubNib(string s, int k)
{
    char a[4][4] = {{'A', '5', '9', 'B'}, {'1', '7', '8', 'F'}, {'6', '0', '2', '3'}, {'C', '4', 'D', 'E'}};
    string s1_1;
    string s1_2;
    string temp;
    for (int i = 0; i < s.size();)
    {
        s1_1 = s.substr(i, 2);
        i += 2;
        s1_2 = s.substr(i, 2);
        temp += a[to_decimal(s1_1)][to_decimal(s1_2)];
        // cout << "\n"<<to_decimal(s1_1) <<"--"<< to_decimal(s1_2)
        //      << "\n";
        i += 2;
        // cout << temp << "->";
    }
    return convert_hex_to_binary(temp, k);
    // incomplete
}

string swap2and4(string s)
{
    string s1, s2, s3, s4;
    s1 = s.substr(0, 4);
    s2 = s.substr(4, 4);
    s3 = s.substr(8, 4);
    s4 = s.substr(12, 4);
    return s1 + s4 + s3 + s2;
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

char mixtable(string s, string k)
{
    // cout << "k" << k << endl;
    string mix;
    if (k == "1")
        mix = "123456789ABCDEF";
    else if (k == "2")
        mix = "2468ACE3175B9FD";
    else if (k == "4")
        mix = "48C37BF62EA51D9";
    else if (k == "9")
        mix = "9182B3A4D5C6F7E";
    // cout << "\nS: " << s<<endl;
    // cout << "decimal: " << to_decimal(s)<<endl;
    // cout << "\npppp: " << mix[to_decimal(s)-1];
    return mix[to_decimal(s) - 1];
}

string MixColumns(string S[4], string Me[4])
{
    string s1, s2, s3, s4;
    // cout << "s1:" << S[0] << endl;
    string temp1, temp2;
    temp1 = mixtable(S[0], Me[0]);
    temp2 = mixtable(S[1], Me[2]);
    // cout << "mix:" << convert_hex_to_binary(temp, 3) << endl;
    s1 = XOR(convert_hex_to_binary(temp1, 3), convert_hex_to_binary(temp2, 3));
    temp1 = mixtable(S[0], Me[1]);
    temp2 = mixtable(S[1], Me[3]);
    s2 = XOR(convert_hex_to_binary(temp1, 3), convert_hex_to_binary(temp2, 3));
    temp1 = mixtable(S[2], Me[0]);
    temp2 = mixtable(S[3], Me[2]);
    s3 = XOR(convert_hex_to_binary(temp1, 3), convert_hex_to_binary(temp2, 3));
    temp1 = mixtable(S[2], Me[1]);
    temp2 = mixtable(S[3], Me[3]);
    s4 = XOR(convert_hex_to_binary(temp1, 3), convert_hex_to_binary(temp2, 3));
    /* cout << "s:" << s1 << endl;
    cout << "s:" << s2 << endl;
    cout << "s:" << s3 << endl;
    cout << "s:" << s4 << endl; */
    return (s1 + s2 + s3 + s4);
}
int main()
{
    string key;
    // key = generate_key(key);
    key = "4AF5";
    string input;
    cout << "(Hex) Key: " << key << "\n";
    string key_binary = convert_hex_to_binary(key, 1);
    cout << "(Binary) Key: " << key_binary << "\n";
    string keys_w[6];
    keys_w[0].append(key_binary.substr(0, 8));
    // cout << key_binary.substr(0, 8) << "->" << keys_w[0];
    keys_w[1].append(key_binary.substr(8, 8));
    // cout << key_binary.substr(8, 8) << "->" << keys_w[1];
    // cout <<"\nW1: " <<SubNib(RotNib(keys_w[1]),2);
    keys_w[2].append(XOR(XOR(keys_w[0], rcon(1)), SubNib(RotNib(keys_w[1]), 2)));
    // cout << keys_w[2];
    keys_w[3].append(XOR(keys_w[2], keys_w[1]));
    // cout << "\nW3: " << SubNib(RotNib(keys_w[3]),2);
    keys_w[4].append(XOR(XOR(keys_w[2], rcon(2)), SubNib(RotNib(keys_w[3]), 2)));
    keys_w[5].append(XOR(keys_w[4], keys_w[3]));
    cout << "\nW0:";
    cout << keys_w[0];
    cout << "\nW1:";
    cout << keys_w[1];
    cout << "\nW2:";
    cout << keys_w[2];
    cout << "\nW3:";
    cout << keys_w[3];
    cout << "\nW4:";
    cout << keys_w[4];
    cout << "\nW5:";
    cout << keys_w[5];
    string round_key[3];
    round_key[0] = keys_w[0] + keys_w[1];
    round_key[1] = keys_w[2] + keys_w[3];
    round_key[2] = keys_w[4] + keys_w[5];
    cout << "\nround Key R0: ";
    cout << round_key[0] << "\n";
    cout << "\nround Key R1: ";
    cout << round_key[1] << "\n";
    cout << "\nround Key R2: ";
    cout << round_key[2] << "\n";
    cout << "Enter Plain text: ";
    getline(cin, input);
    input = input = convert_hex_to_binary(input, 1);
    cout << "Input: " << input;
    // int size_input = input.size();
    string temp;
    string temp2;
    string encrypted;
    // string encrypted_value[size_input];
    string Me[4] = {"1", "4", "4", "1"};
    string IMe[4] = {"9", "2", "2", "9"};
    string S[4];
    // cout << "\nEncrpyted Text: ";
    // for (int i = 0; i < size_input; i++)
    // {
    encrypted = "";
    // round 0
    //  cout<<"BB: "<<binary(to_string(input[i + 1]))<<endl;
    //  temp =binary((input));
    encrypted = XOR(input, round_key[0]);
    // cout << "\nEncrypted:(Again) " << encrypted<<endl;
    // cout << "round:" << round_key[0] << "\n";
    // cout << "\n temp: " << temp<<endl;
    encrypted = SubNib(encrypted, 1);
    // cout << "\nEncrypted:(Again) " << encrypted << endl;
    encrypted = swap2and4(encrypted);
    // cout << "\nEncrypted:(Again) " << encrypted<<endl;
    S[0] = encrypted.substr(0, 4);
    S[1] = encrypted.substr(4, 4);
    S[2] = encrypted.substr(8, 4);
    S[3] = encrypted.substr(12, 4);
    encrypted = MixColumns(S, Me);
    // cout << "\nEncrypted:(Again) " << encrypted << endl;
    encrypted = XOR(encrypted, round_key[1]);
    // cout << "\nEncrypted:(Again) " << encrypted << endl;
    encrypted = SubNib(encrypted, 1);
    // cout << "\nEncrypted:(Again) " << encrypted << endl;
    encrypted = swap2and4(encrypted);
    // cout << "\nEncrypted:(Again) " << encrypted << endl;
    encrypted = XOR(encrypted, round_key[2]);
    // encrypted_value[i] = encrypted;
    cout << "\nEncrpyted text:\t" << encrypted << "\n";
    // cout << encrypted;
    // }
    cout << "\nDecrypted text:\t";
    // for (int i = 0; i < size_input; i++)
    // {
    //     cout << "\n" << encrypted_value[i];
    // }
    // for (int i = 0; i < size_input; i++)
    // {
    // encrypted = encrypted_value;
    encrypted = XOR(round_key[2], encrypted);
    encrypted = swap2and4(encrypted);
    encrypted = ISubNib(encrypted, 1);
    encrypted = XOR(encrypted, round_key[1]);
    S[0] = encrypted.substr(0, 4);
    S[1] = encrypted.substr(4, 4);
    S[2] = encrypted.substr(8, 4);
    S[3] = encrypted.substr(12, 4);
    encrypted = MixColumns(S, IMe);
    encrypted = swap2and4(encrypted);
    encrypted = ISubNib(encrypted, 1);
    encrypted = XOR(encrypted, round_key[0]);
    cout << encrypted;
    // }
    return 0;
}