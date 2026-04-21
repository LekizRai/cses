#include <bits/stdc++.h>
using namespace std;

long long int MOD = 1e9+7;

int main()
{
    long long int n;
    long long int res = 1;
    cin >> n;
    for (int i = 0; i < n; i++) {
        res = (res*2)%MOD;
    }
    cout << res;
    return 0;
}
