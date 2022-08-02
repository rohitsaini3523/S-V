// f = g + h
// h -> misplaced numbers
// g -> row number
// f should be minimum
#include <bits/stdc++.h>
using namespace std;
class node
{
    int a[3][3] ={{0,0,0},{0,0,0},{0,0,0}};

public:
    void get_value(int b[3][3])
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                a[i][j] = b[i][j];
            }
        }
    }
    void display_value()
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cout << a[i][j] << " ";
            }
            cout << "\n";
        }
    }
};
vector<char> nodes(vector<char> node, int n)
{
    char ch;
    if (n > 0)
        while (n--)
        {
            cin >> ch;
            node.push_back(ch);
        }
    else
    {
        cout << "Not possible!\n";
    }
    return node;
}
vector<pair<pair<char, char>, int>> edges(vector<pair<pair<char, char>, int>> edge_pair, int n)
{
    fflush(stdin);
    char ch;
    int temp_cost;
    int count = 0;
    pair<char, char> edge;
    n = edge_pair.size() + n;
    if (n > 0)
        while (ch != 'n')
        {
            count++;
            cout << "First node of edge: ";
            cin >> edge.first;
            cout << "Second node of edge: ";
            cin >> edge.second;
            cout << "Cost of the node: ";
            cin >> temp_cost;
            edge_pair.push_back(make_pair(edge, temp_cost));

            cout << "Do you want to add another edge? (y/n): ";
            cin >> ch;
            if ((count >= (n * (n - 1) / 2)))
            {
                cout << "\nNo More Space of Edges Available!";
                break;
            }
        }
    else
    {
        cout << "Not possible!\n";
    }
    return edge_pair;
}
int h(int intial_state[3][3], int final_state[3][3])
{
    int count = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; i < 3; j++)
        {
            if (intial_state[i][j] != final_state[i][j])
                count++;
        }
    }
    return count;
}
int find_zero(int intial_state[3][3])
{
    int count = 1;
    for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if(intial_state[i][j]==0)
                    return count;
                else
                count++;
            }
        }
        return -1;
}
void swap_value(int a[3][3], int index,int moves)
{
    // node n2[moves];
    int i = 0, j = 0;
    if(index >0 && index<4)
    {
        i = 0;
        j = index - 1;
    }
    else if(index >3 && index<7)
    {
        i = 1;
        j = index - 3;
    }
    else if(index >6 && index<10)
    {
        i = 2;
        j = index - 7;
    }
    // cout << index << "\n";
    // cout <<"\n" <<i << " "<< j;
    // cout << "\n"
    //      << moves;
    // swapping the zero and calculating h value;
    

}
void A_star(vector<char> graph_node, vector<pair<pair<char, char>, int>> graph_edge, list<char> graph_intial_state, list<char> graph_final_state)
{

}
void convert_to_node(int intial_state[3][3], int final_state[3][3])
{
    node n1;
    n1.get_value(intial_state);
    n1.display_value();
    int moves = 0;
    int index = 0;
    while(1)
    {
        index = find_zero(intial_state);
        if(index == 1 || index == 3 || index == 7||index==9)
            moves = 2;
        else if(index == 5)
            moves = 4;
        else if (index == 2 || index == 4 || index == 6 || index == 8)            
            moves = 3;
        // for (int i = 0; i < moves; i++)
        // {
            swap_value(intial_state, index,moves);
            break;
            //}
            // swaping value
        
    }

}

int main()
{
    int n;
    char ch;
    int extra_n;
    int initial_state_8_puzzle[3][3], final_state_8_puzzle[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 0}};
    vector<char> graph_node;
    list<char> graph_intial_state, graph_final_state;
    vector<pair<pair<char, char>, int>> graph_edge;
    int choice;
    while (choice != 5)
    {
        cout << "\nMenu\n1.Create Graph\n2.Update\n3.Path using A*\n4.8-puzzle\n5.Exit\nChoice:  ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            cout << "Enter the number of nodes in graph: ";
            cin >> n;
            cout << "Enter nodes(with spaces): ";
            graph_node = nodes(graph_node, n);
            cout << "Enter Edges: \n";
            graph_edge = edges(graph_edge, n);
            for (int i = 0; i < graph_node.size(); i++)
            {
                cout << graph_node[i] << " ";
            }
            for (int i = 0; i < graph_edge.size(); i++)
            {
                cout << "\n{ " << graph_edge[i].first.first << " ," << graph_edge[i].first.second << " } - cost: " << graph_edge[i].second;
            }

            break;
        }
        case 2:
        {
            if (graph_node.size() == 0)
            {
                cout << "Graph is Empty!\n";
            }
            cout << "Enter the number of nodes to add in graph: ";
            cin >> extra_n;
            cout << "Enter extra nodes(with spaces): ";
            graph_node = nodes(graph_node, extra_n);
            cout << "Enter new Edges: \n";
            graph_edge = edges(graph_edge, extra_n);
            for (int i = 0; i < graph_node.size(); i++)
            {
                cout << graph_node[i] << " ";
            }
            for (int i = 0; i < graph_edge.size(); i++)
            {
                cout << "\n{ " << graph_edge[i].first.first << " ," << graph_edge[i].first.second << " } - cost: " << graph_edge[i].second;
            }
            break;
        }
        case 3:
        {
            if (graph_node.size() == 0)
            {
                cout << "Graph is Empty!\n";
                break;
            }
            cout << "\nEnter intial state of graph: ";
            int i = 0;
            while (i < n)
            {
                cout << "Intial state " << i + 1 << ":";
                cin >> ch;
                graph_intial_state.push_back(ch);
                i++;
            }
            cout << "\nEnter Final state of graph: ";
            while (i < n)
            {
                fflush(stdin);
                cout << "Intial state " << i + 1 << ":";
                cin >> ch;
                graph_intial_state.push_back(ch);
                i++;
            }
            list<char>::iterator it;
            cout << "\nInitial States : ";
            for (it = graph_intial_state.begin(); it != graph_intial_state.end(); it++)
            {
                cout << *it << " ";
            }
            cout << "\nFinal States : ";
            for (it = graph_final_state.begin(); it != graph_final_state.end(); it++)
            {
                cout << *it << " ";
            }
            A_star(graph_node, graph_edge, graph_intial_state, graph_final_state);
            break;
        }
        case 4:
        {
            int i = 0;
            cout << "\nIntial States[0-8] : ";
            fflush(stdin);
            for (int k = 0; k < 3; k++)
            {
                for (int l = 0; l < 3; l++)
                {
                    cin >> initial_state_8_puzzle[k][l];
                }
            }
            cout << "\nInput Puzzle:\n";
            convert_to_node(initial_state_8_puzzle, final_state_8_puzzle);
            break;
        }
        case 5:
        {
            cout << "Exit!\n";
            break;
        }
        default:
            cout << "Wrong Choice!\n";
            break;
        }
    }

    // a_star(graph_node, graph_edge);
    return 0;
}