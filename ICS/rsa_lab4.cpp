#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    while (b != 0)
    {
        int rem = a % b;
        a = b;
        b = rem;
    }
    return a;
}
int main()
{
    int p, q;
    cin >> p >> q;
    int n = p * 1;
    int e;
    int f_n = (p - 1) * (q - 1);
    cout << f_n<<endl;
    for (int i = 2; i < f_n; i++)
    {
        if(gcd(i,f_n)==1)
        {
            e = i;
            break;
        } 
    }
    cout << e;
    
    // cout << gcd(100, 10);
    return 0;
}