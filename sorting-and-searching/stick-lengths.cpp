#include <bits/stdc++.h>
using namespace std;


int main()
{
    int n, id;
    cin >> n;
    vector<long long int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    sort(p.begin(), p.end());
    if (int(p.size())%2 == 1) {
        long long int res = 0;
        id = int(p.size())/2;
        for (auto &it: p) {
            res += abs(it-p[id]);
        }
        cout << res;
    }
    else {
        long long int res1, res2;
        res1 = 0; res2 = 0;
        id = int(p.size())/2;
        for (auto &it: p) {
            res1 += abs(it-p[id]);
            res2 += abs(it-p[id+1]);
        }
        cout << min(res1, res2);
    }
    return 0;
}
