#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1024;

int main()
{
    int k;
    cin >> k;
    int n = 1 << k;

    char M[MAX_N][MAX_N];

    M[0][0] = '+';

    for (int i = 0; i < k; ++i)
    {
        int size = 1 << i;
        for (int row = 0; row < size; ++row)
        {
            for (int col = 0; col < size; ++col)
            {
                M[row + size][col] = M[row][col];
                M[row][col + size] = M[row][col];
                M[row + size][col + size] = M[row][col];
                M[row][col] = (M[row][col] == '+' ? '*' : '+');
            }
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << M[i][j];
        }
        cout << endl;
    }

    return 0;
}
