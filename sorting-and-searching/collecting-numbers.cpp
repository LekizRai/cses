#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, id;
    cin >> n;
    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> id;
        x[id-1] = i;
    }
    int cur_id = -1;
    int res = 1;
    for (int i = 0; i < n; i++) {
        if (cur_id > x[i]) {
            res += 1;
        }
        cur_id = x[i];
    }
    cout << res;
    return 0;
}
