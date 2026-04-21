#include <bits/stdc++.h>
using namespace std;

#define lli long long int


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lli n, a, b, x, res;
    cin >> n >> a >> b;
    map<int, lli> sum;
    sum[-1] = 0;
    for (int i = 0; i < n; i++) {
        cin >> x;
        sum[i] = sum[i-1]+x;
    }
    multiset<lli> min_sum;
    min_sum.insert(sum[-1]);
    res = -1e18;
    for (int i = a-1; i < n; i++) {
        if (sum[i]-(*min_sum.begin()) > res) {
            res = sum[i]-(*min_sum.begin());
        }
        min_sum.insert(sum[i-a+1]);
        if (int(min_sum.size()) > b-a+1) {
            auto it = min_sum.find(sum[i-b]);
            if (it != min_sum.end()) {
                min_sum.erase(it);
            }
        }
    }
    cout << res;
    return 0;
}
