#include <bits/stdc++.h>
using namespace std;


int main()
{
    int n;
    cin >> n;
    map<int, int> id;
    vector<int> k(n);
    for (int i = 0; i < n; i++) {
        cin >> k[i];
        id[k[i]] = -1;
    }
    int max_res = -1;
    int res = 0;
    int prev_id = 0;
    for (int i = 0; i < n; i++) {
        if (id[k[i]] != -1) {
            max_res = max(res, max_res);
            res -= id[k[i]]-prev_id;
            for (int j = prev_id; j <= id[k[i]]-1; j++) {
                id[k[j]] = -1;
            }
            prev_id = id[k[i]]+1;
            id[k[i]] = i;
        }
        else {
            res += 1;
            id[k[i]] = i;
        }
    }
    max_res = max(max_res, res);
    cout << max_res;
    return 0;
}
