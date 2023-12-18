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
        string number;
        cin >> number;
        if (number[number.size() - 1] % 2 == 0)
            cout << "even" << '\n';
        else
            cout << "odd" << '\n';
    }
    return 0;
}