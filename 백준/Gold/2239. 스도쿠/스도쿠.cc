#include <iostream>
#include <string>

using namespace std;

int table[9][9];
bool rowCheck[9][9];
bool colCheck[9][9];
bool boxCheck[9][9];
bool foundSolution = false;

void solve(int index)
{
    if (index == 81)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
                cout << table[i][j];
            cout << "\n";
        }
        foundSolution = true;
    }

    int x = index / 9;
    int y = index % 9;

    if (foundSolution)
        return;

    if (table[x][y] == 0)
    {
        for (int i = 1; i <= 9; i++)
        {
            if (!rowCheck[x][i] && !colCheck[y][i] && !boxCheck[(x / 3) * 3 + (y / 3)][i])
            {
                rowCheck[x][i] = true;
                colCheck[y][i] = true;
                boxCheck[(x / 3) * 3 + (y / 3)][i] = true;
                table[x][y] = i;
                solve(index + 1);
                rowCheck[x][i] = false;
                colCheck[y][i] = false;
                boxCheck[(x / 3) * 3 + (y / 3)][i] = false;
                table[x][y] = 0;
            }
        }
    }
    else
        solve(index + 1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string line;

    for (int i = 0; i < 9; i++)
    {
        cin >> line;
        for (int j = 0; j < 9; j++)
        {
            table[i][j] = line[j] - '0';
            if (table[i][j] != 0)
            {
                rowCheck[i][table[i][j]] = true;
                colCheck[j][table[i][j]] = true;
                boxCheck[(i / 3) * 3 + (j / 3)][table[i][j]] = true;
            }
        }
    }

    solve(0);

    return 0;
}
