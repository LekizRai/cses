#include <bits/stdc++.h>
using namespace std;

#define MOD int(1e9+7)


int main()
{
    int n;
    cin >> n;
    vector<int> res(n+1);
    res[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= min(6, i); j++) {
            res[i] = (res[i]+res[i-j])%MOD;
        }
    }
    cout << res[n];
    return 0;
}
