#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    while (N--)
    {

        int size;
        cin >> size;
        if (size == 1)
        {
            cout << "#\n\n";
        }
        else if (size == 2)
        {
            cout << "##\n##\n\n";
        }
        else
        {
            for (int i = 0; i < size; i++)
            {
                cout << "#";
            }
            cout << "\n";
            for (int i = 0; i < size - 2; i++)
            {
                cout << "#";
                for (int j = 0; j < size - 2; j++)
                {
                    cout << "J";
                }
                cout << "#\n";
            }
            for (int i = 0; i < size; i++)
            {
                cout << "#";
            }
            cout << "\n\n";
        }
    }

    return 0;
}