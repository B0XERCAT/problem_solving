#include <iostream>
#include <string>
#include <vector>
#define ll long long
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int A, B, C, D;
    cin >> A >> B >> C >> D;
    string a = to_string(A) + to_string(B);
    string b = to_string(C) + to_string(D);
    ll result = stoll(a) + stoll(b);
    cout << result;

    return 0;
}