#include <bits/stdc++.h>
using namespace std;


long long int x[200000];
long long int sum[200000];
map<int, long long int> min_sum;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    if (n == 1) {
        cout << x[0];
        return 0;
    }
    min_sum[-1] = 0;
    sum[0] = x[0];
    for (int i = 1; i < n; i++) {
        sum[i] = sum[i-1] + x[i];
        min_sum[i-1] = min(min_sum[i-2], sum[i-1]);
    }
    long long int res = x[0];
    for (int i = 0; i < n; i++) {
            res = max(res, sum[i]-min_sum[i-1]);
    }
    cout << res;
    return 0;
}
