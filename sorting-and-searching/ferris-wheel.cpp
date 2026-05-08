#include <bits/stdc++.h>
using namespace std;


int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> p(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    sort(p.begin(), p.end());
    int i = 0;
    int j = n-1;
    int res = 0;
    while (i < j) {
        if (p[i] + p[j] <= x) {
            i += 1;
            j -= 1;
        }
        else {
            j -= 1;
        }
        res += 1;
    }
    if (i == j) res += 1;
    cout << res;
    return 0;
}
