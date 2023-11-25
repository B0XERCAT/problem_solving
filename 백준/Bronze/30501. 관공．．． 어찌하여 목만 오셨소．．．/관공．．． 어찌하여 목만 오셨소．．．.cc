#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    string result;
    cin >> N;
    while (N--)
    {
        string name;
        cin >> name;
        for (int i = 0; i < name.size(); i++)
            if (name[i] == 'S')
                result = name;
    }
    cout << result;

    return 0;
}