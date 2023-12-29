#include <iostream>
#include <vector>
#include <algorithm>
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
        int n;
        cin >> n;
        printf("Pairs for %d: ", n);
        for (int i = 1; i * 2 < n; i++)
        {
            if (i != 1)
                printf(", ");
            printf("%d %d", i, n - i);
        }
        printf("\n");
    }
    return 0;
}