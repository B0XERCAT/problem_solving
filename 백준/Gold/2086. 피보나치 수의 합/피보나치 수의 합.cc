#include <iostream>
#include <vector>
#define vv vector<vector<long long>> 
#define MOD 1000000000
using namespace std;


vv mult(vv a, vv b) {
    vv c(2, vector<long long>(2, 0));
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++) {
            long long sum = 0;
            for (int k = 0; k < 2; k++){
                sum += ((a[i][k] % MOD) * (b[k][j] % MOD)) % MOD;
                sum %= MOD;
            }
            c[i][j] = sum;
        }
    return c;
}

vv expo(vv v, long long k) {
    if (k == 0){
        v = {{0, 0}, {0, 0}};
        return v;
    }
    if (k == 1)
        return v;
    if (k == 2)
        return mult(v, v);

    vv temp = expo(v, k / 2);
    temp = mult(temp, temp);
    if(k % 2 == 1) 
        temp = mult(temp, v);
    return temp;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    vv matrix = {{1,1}, {1,0}};

    long long A, B, result = 0;
    cin >> A >> B;
    A %= 1500000000;
    B %= 1500000000;

    result += (expo(matrix, B + 2)[1][0] - expo(matrix, A + 1)[1][0] + MOD) % MOD;
    cout << result;
    return 0;
}
