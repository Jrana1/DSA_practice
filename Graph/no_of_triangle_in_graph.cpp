
#include <bits/stdc++.h>
using namespace std;

void print_mat(vector<int> *mat)
{

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

void multiply_matrix(vector<int> *graph1, vector<int> *graph2, vector<int> *res)
{
    // print_mat(graph1);
    // graph1[0][0] = 22;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {

            int ans = 0;
            for (int k = 0; k < 5; k++)
            {
                ans = ans + graph1[i][k] * graph2[k][j];
            }
            res[i].push_back(ans);
        }
    }
    // print_mat(res);
    //  return res;
}

int find_trace_of_a_matrix(vector<int> *mat)
{
    int trace = 0;
    for (int i = 0; i < 5; i++)
    {
        trace = trace + mat[i][i];
    }
    return trace;
}
int main()
{

    vector<int> graph[5] = {

        {0, 1, 0, 0, 1},
        {1, 0, 1, 1, 1},
        {0, 1, 0, 1, 0},
        {0, 1, 1, 0, 1},
        {1, 1, 0, 1, 0}};
    vector<int> res[5];
    vector<int> res1[5];
    multiply_matrix(graph, graph, res);
    multiply_matrix(graph, res, res1);
    // print_mat(res1);
    cout << "No. of Cycle with length 3(Triangle) = " << find_trace_of_a_matrix(res1) / 6 << endl;
    return 0;
}