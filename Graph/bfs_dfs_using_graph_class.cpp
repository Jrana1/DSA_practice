#include <bits/stdc++.h>
using namespace std;

class Graph
{

private:
    int V;
    vector<bool> visited;
    vector<int> *adj_mat;

public:
    Graph(int V = 1)
    {
        this->V = V;
        adj_mat = new vector<int>[V];
    }
    ~Graph();
    void add_edge(int v, int w);
    void print_graph() const;
    void show_degree_of_each_node() const;
    int number_of_edges() const;
    void BFS(int start);
    bool isConnected() const;
};

bool Graph::isConnected() const
{
    for (auto i = 0; i < V; i++)
    {
        if (visited[i] == false)
        {
            return false;
        }
    }
    return true;
}

void Graph::BFS(int start)
{

    // init visited array with false
    for (int i = 0; i < V; i++)
    {
        visited.push_back(false);
    }

    queue<int> q;
    cout << start << " ";
    q.push(start);
    visited[start] = true;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto i : adj_mat[u])
        {
            if (visited[i] == false)
            {
                cout << i << " ";
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

int Graph::number_of_edges() const
{
    int sum_degree = 0;
    for (int i = 0; i < V; i++)
    {

        for (auto v : adj_mat[i])
        {
            sum_degree++;
        }
    }
    return sum_degree / 2;
}

void Graph::show_degree_of_each_node() const
{
    for (int i = 0; i < V; i++)
    {
        int cnt = 0;
        cout << "d(" << i << ")=";
        for (auto v : adj_mat[i])
        {
            cnt++;
        }
        cout << cnt << endl;
    }
}

void Graph::add_edge(int v, int u)
{

    adj_mat[v].push_back(u);
    adj_mat[u].push_back(v);
}
Graph::~Graph()
{

    // for (int i = 0; i < V; i++)
    // {
    //     delete[] adj_mat;
    // }
}
void Graph::print_graph() const
{
    for (int i = 0; i < V; i++)
    {
        cout << i << "->";
        for (auto j : adj_mat[i])
        {
            cout << j << " ";
        }
        cout << endl;
    }
}
int main()
{
    Graph g1(5);
    g1.add_edge(0, 1);
    g1.add_edge(0, 2);
    // g1.add_edge(1, 4);
    g1.add_edge(1, 3);
    g1.add_edge(2, 3);
    // g1.add_edge(3, 4);
    // g1.print_graph();
    // cout << g1.number_of_edges() << endl;
    g1.BFS(1);
    cout << endl
         << g1.isConnected() << endl;

    return 0;
}