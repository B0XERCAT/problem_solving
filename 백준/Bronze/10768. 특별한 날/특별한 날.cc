#include <iostream>
#define ll long long
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int M, D;
    cin >>  M >> D;
    if(M > 2)
        cout << "After";
    else if(M == 2){
        if(D > 18)
            cout << "After";
        else if(D==18)
            cout << "Special";
        else
            cout << "Before";
    }
    else
        cout << "Before";

    return 0;
}