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

    if (visited[v] == 0)
    {
        cout << v << ",";
        visited[v] = 1;
    }
    for (int i = 1; i < 8; i++)
    {
        if (visited[i] == 0 && graph[v][i] == 1)
        {
            dfs(i);
        }
    }
}
int main()
{

    dfs(6);

    return 0;
}
