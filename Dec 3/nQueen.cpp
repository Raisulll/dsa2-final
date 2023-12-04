#include <bits/stdc++.h>
using namespace std;
int n;
int board[100][100];
bool issafe(int row, int col)
{
    for (int i = 0; i < row; ++i)
    {
        if (board[i][col])
            return false;
    }
    for (int i = row, j = col; i >= 0 and j >= 0; i--, j--)
    {
        if (board[i][j])
            return false;
    }
    for (int i = row, j = col; i >= 0 and j < n; i--, j++)
    {
        if (board[i][j])
            return false;
    }
    return true;
}
void queen(int row)
{
    if (row == n)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (board[i][j])
                    cout << "Q ";
                else
                    cout << ". ";
            }
            cout << endl;
        }
        cout << endl;
        return;
    }
    for (int i = 0; i < n; ++i)
    {
        if (issafe(row, i))
        {
            board[row][i] = 1;
            queen(row + 1);
            board[row][i] = 0;
        }
    }
}
int main()
{
    memset(board, 0, sizeof board);
    cin >> n;
    queen(0);
}