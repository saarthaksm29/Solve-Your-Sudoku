#include <bits/stdc++.h>
using namespace std;

bool canplace(int mat[][9], int i, int j, int n, int number)
{
    for (int x = 0; x < n; x++)
    {
        if (mat[x][j] == number or mat[i][x] == number)
        {
            return false;
        }
    }
    //Now it is easy to check for the number in the row and column but
    //we need to find if that number is present in the subgrid or not
    //for that if we know the starting pt of the subgrid then we can check for that grid
    int rn = sqrt(n);
    int sx = (i / rn) * rn;
    int sy = (j / rn) * rn;

    for (int x = sx; x < sx + rn; x++)
    {
        for (int y = sy; y < sy + rn; y++)
        {
            if (mat[x][y] == number)
            {
                return false;
            }
        }
    }
    return true;
}
bool sudokusolver(int mat[][9], int i, int j, int n)
{
    //Base case
    if (i == n)
    {
        //print the answer
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }

        return true;
    }
    //Case row end hogyi toh ab ham next row pe call karenge aur col 0 hojayega
    if (j == n)
    {
        return sudokusolver(mat, i + 1, 0, n);
    }
    //Skip the pre-filled cells
    if (mat[i][j] != 0)
    {
        return sudokusolver(mat, i, j + 1, n);
    }
    //Recursive case
    for (int number = 1; number <= n; number++)
    {
        if (canplace(mat, i, j, n, number))
        {
            //Assume jo number rakhre hai wahi sahi hai
            mat[i][j] = number;
            bool couldwesolve = sudokusolver(mat, i, j + 1, n);
            if (couldwesolve)
            {
                return true;
            }
        }
    }
    //Backtrack step
    mat[i][j] = 0;
    return false;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int mat[9][9] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9},
    };
    sudokusolver(mat, 0, 0, 9);

    return 0;
}
