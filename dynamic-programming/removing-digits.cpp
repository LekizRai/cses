#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, tmp;
    cin >> n;
    vector<int> res(n+1, 1e9+7);
    res[0] = 0;
    for (int i = 1; i <= n; i++) {
        tmp = i;
        while (tmp != 0) {
            res[i] = min(res[i], res[i-tmp%10]+1);
            tmp /= 10;
        }
    }
    cout << res[n];
    return 0;
}
