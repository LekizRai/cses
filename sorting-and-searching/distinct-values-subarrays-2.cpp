#include <bits/stdc++.h>
using namespace std;

#define lli long long int


lli compute_num(lli k)
{
    return (k*(k+1))/2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lli n, k, cur_id, res;
    cin >> n >> k;
    vector<lli> x(n);
    map<int, int> x2id;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        x2id[x[i]] = -1;
    }
    set<lli> xset;
    cur_id = 0;
    res = 0;
    for (int i = 0; i < n; i++) {
        if (xset.find(x[i]) == xset.end()) {
            if (int(xset.size()) < k) xset.insert(x[i]);
            else {
                res += compute_num((lli)(i)-cur_id);
                xset.insert(x[i]);
                while (cur_id < i) {
                    if (x2id[x[cur_id]] == cur_id) {
                        xset.erase(x[cur_id]);
                        cur_id += 1;
                        break;
                    }
                    cur_id += 1;
                }
                res -= compute_num((lli)(i)-cur_id);
            }
        }
        x2id[x[i]] = max(x2id[x[i]], i);
    }
    res += compute_num(n-cur_id);
    cout << res;
    return 0;
}
