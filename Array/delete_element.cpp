
#include <iostream>
using namespace std;

void delete_element(int *A, int len, int k)
{
    int i;
    for (i = 0; i < len; i++)
    {
        if (A[i] == k)
        {
            break;
        }
    }
    while (i <= len)
    {
        A[i] = A[i + 1];
        i++;
    }
}

int main()
{

    int a[4] = {3, 2, 9, 1};
    delete_element(a, 4, 9);
    for (int i = 0; i < 3; i++)
    {
        cout << a[i] << endl;
    }

    return 0;
}