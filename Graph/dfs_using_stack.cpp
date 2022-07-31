#include <bits/stdc++.h>
using namespace std;
int graph[8][8] = {
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 1, 1, 1, 0, 0, 0},
    {0, 1, 0, 1, 0, 0, 0, 0},
    {0, 1, 1, 0, 1, 1, 0, 0},
    {0, 1, 0, 1, 0, 1, 0, 0},
    {0, 0, 0, 1, 1, 0, 1, 1},
    {0, 0, 0, 0, 0, 1, 0, 1},
    {0, 0, 0, 0, 0, 1, 1, 0}};
int visited[8] = {0};
void dfs(int v)
{

    stack<int> vertices;
    cout << v << ",";
    visited[v] = 1;
    vertices.push(v);
    while (!vertices.empty())
    {
        int u = vertices.top();
        vertices.pop();
        for (int i = 0; i < 8; i++)
        {
            if (visited[i] == 0 && graph[u][i] == 1)
            {
                cout << i << " ,";
                visited[i] = 1;
                vertices.push(i);
            }
        }
    }
}
int main()
{
    dfs(3);
    return 0;
}