
#include <bits/stdc++.h>
using namespace std;

void add_edges(vector<int> *adj, int u, int v)
{

    adj[u].push_back(v);
    adj[v].push_back(u);
}
void print(vector<int> *adj, int v)
{

    for (int i = 0; i < v; i++)
    {
        cout << i << "->";
        for (auto j : adj[i])
        {
            cout << j << " ";
        }
        cout << endl;
    }
}
int main()
{

    int v = 5;
    vector<int> adj[v];
    add_edges(adj, 0, 1);
    add_edges(adj, 0, 4);
    add_edges(adj, 1, 2);
    add_edges(adj, 1, 3);
    add_edges(adj, 1, 4);
    add_edges(adj, 3, 4);
    add_edges(adj, 2, 3);
    print(adj, v);

    return 0;
}