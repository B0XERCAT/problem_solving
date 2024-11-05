#include <iostream>
#include <string>
using namespace std;

int is_prime(int n)
{
    if (n == 1)
        return 0;
    if (n == 2)
        return 1;
    if (n % 2 == 0)
        return 0;
    for (int i = 3; i * i <= n; i += 2)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

int int_length(int n)
{
    return to_string(n).length();
}

int is_palindrome(int n)
{
    string str = to_string(n);
    int len = int_length(n);

    for (int i = 0; i < len / 2; i++)
    {
        if (str[i] != str[len - i - 1])
            return 0;
    }
    return 1;
}

int main()
{
    int N;
    cin >> N;

    while (1)
    {
        if (is_palindrome(N) && is_prime(N))
        {
            cout << N;
            return 0;
        }
        else
        {
            N++;
        }
    }
    return 0;
}