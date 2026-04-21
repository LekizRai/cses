#include <bits/stdc++.h>
using namespace std;

#define lli long long int

lli mod(lli a, lli b)
{
    return ((a%b)+b)%b;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lli n, res;
    cin >> n;
    vector<lli> a(n);
    vector<lli> cumul(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i == 0) cumul[i] = a[i];
        else cumul[i] = cumul[i-1]+a[i];
    }
    map<lli, vector<int>> mod2id;
    for (int i = 0; i < n; i++) {
        if (mod2id.count(mod(cumul[i], n)) > 0) {
            mod2id[mod(cumul[i], n)].push_back(i);
        }
        else {
            mod2id[mod(cumul[i], n)] = vector<int> {i};
        }
    }
    res = 0;
    if (mod2id.count(0) > 0) {
        res += int(mod2id[0].size());
    }
    for (int i = 0; i < n; i++) {
        if (mod2id.count(mod(cumul[i], n)) > 0) {
            res += mod2id[mod(cumul[i], n)].end()-lower_bound(mod2id[mod(cumul[i], n)].begin(), mod2id[mod(cumul[i], n)].end(), i+1);
        }
    }
    cout << res;
    return 0;
}
