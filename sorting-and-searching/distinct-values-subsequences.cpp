#include <bits/stdc++.h>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, x;
    cin >> n;
    set<int> val;
    map<int, long long int> num;
    vector<int> _x;
    long long int mod = 1e9+7;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (val.find(x) != val.end()) {
            num[x] += 1;
        }
        else {
            val.insert(x);
            _x.push_back(x);
            num[x] = 1;
        }
    }
    long long int res = 1;
    for (auto &it: _x) {
        res = (res*(num[it]+1))%mod;
    }
    cout << (res-1)%mod;
    return 0;
}
