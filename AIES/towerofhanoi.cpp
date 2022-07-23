#include <iostream>
using namespace std;
int count = 0;

int tower_of_hanoi(int n, char from_tower, char to_tower, char auxill_tower)
{
    count++;
    if (n == 1)
    {
        cout << "Move Disk: 1 from " << from_tower << " to tower " << to_tower << "\n";
        return count;
    }
    tower_of_hanoi(n - 1, from_tower, auxill_tower, to_tower);
    cout << "Move Disk: " << n << " from " << from_tower << " to tower " << to_tower << "\n";
    tower_of_hanoi(n - 1, auxill_tower, to_tower, from_tower);
}

int main()
{
    int n_disk;
    cout << "\nEnter Number of Disk: ";
    cin >> n_disk;
    int n = tower_of_hanoi(n_disk, 'A', 'B', 'C');
    cout << "Total Moves: " << n;
    return 0;
}