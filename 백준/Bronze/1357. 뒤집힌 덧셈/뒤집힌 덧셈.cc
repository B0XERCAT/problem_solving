#include <iostream>
#include <string>
using namespace std;

int reverse(string num)
{
    string temp;
    for (int i = num.size() - 1; i >= 0; i--)
        temp += num[i];
    return stoi(temp);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string X, Y;
    cin >> X >> Y;
    int result = reverse(to_string(reverse(X) + reverse(Y)));
    cout << result;
    return 0;
}