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

void bfs(int v)
{
    queue<int> vertices;
    cout << v << ",";
    visited[v] = 1;
    vertices.push(v);
    while (!vertices.empty())
    {
        int u = vertices.front();
        vertices.pop();
        for (int i = 1; i < 8; i++)
        {
            if (visited[i] == 0 && graph[u][i] == 1)
            {
                visited[i] = 1;
                cout << i << ",";
                vertices.push(i);
            }
        }
    }
}
int main()
{
    bfs(7);

    return 0;
}