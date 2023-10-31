#include <iostream>
#include <string>
using namespace std;

string strawberry[28] = {
    "VVV딸기\n",
    "VV딸기V\n",
    "VV딸기딸기\n",
    "V딸기VV\n",
    "V딸기V딸기\n",
    "V딸기딸기V\n",
    "V딸기딸기딸기\n",
    "딸기VVV\n",
    "딸기VV딸기\n",
    "딸기V딸기V\n",
    "딸기V딸기딸기\n",
    "딸기딸기VV\n",
    "딸기딸기V딸기\n",
    "딸기딸기딸기V\n",
    "딸기딸기딸기딸기\n",
    "딸기딸기딸기V\n",
    "딸기딸기V딸기\n",
    "딸기딸기VV\n",
    "딸기V딸기딸기\n",
    "딸기V딸기V\n",
    "딸기VV딸기\n",
    "딸기VVV\n",
    "V딸기딸기딸기\n",
    "V딸기딸기V\n",
    "V딸기V딸기\n",
    "V딸기VV\n",
    "VV딸기딸기\n",
    "VV딸기V\n"};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  long long T;
  cin >> T;
  while (T--)
  {
    long long N;
    cin >> N;
    cout << strawberry[(N - 1) % 28];
  }
  return 0;
}