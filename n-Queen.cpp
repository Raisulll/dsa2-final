// n queen problem
#include <bits/stdc++.h>
using namespace std;

int n;
int dp[100][100];
int counter = 0;

void init(int a)
{
    for (int i = 0; i < a; i++)
        for (int j = 0; j < a; j++)
            dp[i][j] = 0;
}

bool isSafe(int row, int col)
{
    int i, j;
    // Check the column to see if it has a queen
    for (i = 0; i < row; i++)
        if (dp[i][col] == 1)
            return false;

    // Check upper diagonal on the left side
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (dp[i][j] == 1)
            return false;

    // Check upper diagonal on the right side
    for (i = row, j = col; i >= 0 && j < n; i--, j++)
        if (dp[i][j] == 1)
            return false;

    return true;
}

void printSolution()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (dp[i][j] == 1)
                cout << "Q ";
            else
                cout << "- ";
        }
        cout << endl;
    }
    cout << endl;
}

bool backtracking(int row)
{
    if (row == n)
    {
        counter++;
        printSolution();
        return true;
    }
    bool ans = false;
    for (int j = 0; j < n; j++)
    {
        if (isSafe(row, j))
        {
            dp[row][j] = 1;
            ans = backtracking(row + 1);
            dp[row][j] = 0;
        }
    }
}

int main()
{
    cout << "Enter value of n: ";
    cin >> n;
    init(n);
    backtracking(0);
    if (counter == 0)
    {
        cout << "No solutions found." << endl;
    }
    else
    {
        cout << "Total solutions: " << counter << endl;
    }
}