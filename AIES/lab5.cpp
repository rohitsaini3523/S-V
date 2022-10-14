#include <iostream>
using namespace std;

class graph
{
    int cost[10][10];
    int city;

public:
    graph()
    {
        city = 0;
        cout << "Enter Number of Cities: ";
        cin >> city;
        for (int i = 0; i < city; i++)
            for (int j = 0; j < city; j++)
            {
                cost[i][j] = 0;
            }
    }
    void create()
    {
        char ch;
        for (int i = 0; i < city; i++)
        {
            for (int j = i + 1; j < city; j++)
            {
                cout << "\n Is there a connection between " << i << " and " << j << ":"
                     << "(y or n)"
                     << ":  ";
                cin >> ch;
                if (ch == 'y')
                {
                    cout << "\nEnter the cost of edge " << i << " and " << j << ": ";
                    cin >> cost[i][j];
                    cost[j][i] = cost[i][j];
                }
            }
        }
    }
    void display()
    {
        for (int i = 0; i < city; i++)
        {
            for (int j = 0; j < city; j++)
            {
                cout << cost[i][j] << "\t";
            }
            cout << "\n";
        }
    }
    void TSP()
    {
            
    }
};
int main()
{
    int ch;
    graph g;
    do
    {
        cout << "\n_____MENU______\n1.Create\n2.Display\n3.TSP\n4.Exit\nChoice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            g.create();
            break;
        case 2:
            g.display();
            break;
        case 3:
            g.TSP();
            break;
        case 4:
            break;
        }
    } while (ch != 4);
    return 0;
}