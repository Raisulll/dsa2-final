#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
ll board[100][100];
bool isSafe(ll row, ll col)
{
    // for column
    for (ll i = 0; i < row; ++i)
    {
        if (board[i][col] == 1)
            return false;
    }
    // upper left diagonal
    for (ll i = row, j = col; i >= 0 and j >= 0; --i, --j)
    {
        if (board[i][j] == 1)
            return false;
    }
    // upper right diagonal
    for (ll i = row, j = col; i >= 0 and j < n; --i, ++j)
    {
        if (board[i][j] == 1)
            return false;
    }
    return true;
}
void nqueen(ll row)
{
    if (row == n)
    {
        for (ll i = 0; i < n; ++i)
        {
            for (ll j = 0; j < n; ++j)
            {
                if (board[i][j] == 1)
                    cout <<"Q"<< " ";
                else
                    cout << ". ";
            }
            cout << endl;
        }
        cout << endl;
        return;
    }
    for (ll i = 0; i < n; ++i)
    {
        if (isSafe(row, i))
        {
            board[row][i] = 1;
            nqueen(row + 1);
            board[row][i] = 0;
        }
    }
}
int main()
{
    cin >> n;
    memset(board, 0, sizeof(board));
    nqueen(0);
    return 0;
}