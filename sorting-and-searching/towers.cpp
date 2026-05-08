#include <bits/stdc++.h>
using namespace std;


int main()
{
    int n, k;
    cin >> n;
    vector<int> res;
    for (int i = 0; i < n; i++) {
        cin >> k;
        auto it = upper_bound(res.begin(), res.end(), k);
        if (it == res.end()) {
            res.push_back(k);
        }
        else {
            (*it) = k;
        }
    }
    cout << res.size();
    return 0;
}
