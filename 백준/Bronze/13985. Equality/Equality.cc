#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b, c;
    scanf("%d + %d = %d", &a, &b, &c);
    if (a + b == c)
        printf("YES");
    else
        printf("NO");

    return 0;
}