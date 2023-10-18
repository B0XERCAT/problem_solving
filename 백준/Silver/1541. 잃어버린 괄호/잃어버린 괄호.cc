#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#define ll long long
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<string> formula;
    string line;
    string curNum;
    cin >> line;
    for (int i = 0; i < line.size(); i++)
    {
        if (line[i] == '-')
        {
            formula.push_back(curNum);
            curNum.clear();
            formula.push_back("-");
        }
        else if (line[i] == '+')
        {
            formula.push_back(curNum);
            curNum.clear();
            formula.push_back("+");
        }
        else
            curNum += line[i];
    }

    formula.push_back(curNum);

    int result = 0;
    int sum = 0;

    vector<int> subtract;

    for (int i = 0; i < formula.size(); i++)
    {
        if (formula[i] == "-")
        {
            subtract.push_back(sum);
            sum = 0;
        }
        else if (formula[i] == "+")
        {
            sum += stoi(formula[i + 1]);
            i++;
        }
        else
            sum = stoi(formula[i]);
    }
    
    if (sum != 0)
        subtract.push_back(sum);

    result = subtract[0];

    for (int i = 1; i < subtract.size(); i++)
        result -= subtract[i];

    cout << result;

    return 0;
}