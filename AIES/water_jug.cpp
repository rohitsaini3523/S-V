#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int pour_water(int jug1, int jug2, int litre_req)
{
    int from = jug1;
    int to = 0;
    int steps = 1;

    while (from != litre_req && to != litre_req)
    {
        int temp = min(from, jug2 - to);
        to += temp;
        from -= temp;
        // cout << from << " " << to << " " << temp << "\n";
        steps++;
        if (from == litre_req || to == litre_req)
            break;
        if (from == 0)
        {
            from = jug1;
            steps++;
        }
        if (to == jug2)
        {
            to = 0;
            steps++;
        }
    }
    return steps;
}

int minsteps(int jug1, int jug2, int litre_req)
{
    if (jug1 > jug2)
        swap(jug1, jug2);
    if (litre_req > jug2)
        return -1;
    if ((litre_req % gcd(jug2, jug1)) != 0)
        return -1;

    return min(pour_water(jug2, jug1, litre_req), pour_water(jug1, jug2, litre_req));
}

int main()
{
    int jug1, jug2, required_water;
    cout << "Capacity of Jug1: ";
    cin >> jug1;
    cout << "Capacity of Jug2: ";
    cin >> jug2;
    cout << "Required Water: ";
    cin >> required_water;
    cout << "Required Steps: " << minsteps(jug1, jug2, required_water);
    return 0;
}