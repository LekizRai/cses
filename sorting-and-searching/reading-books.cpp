#include <bits/stdc++.h>
using namespace std;

#define lli long long int


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lli n, t, sum, cumul, limit;
    cin >> n;
    vector<lli> ts;
    sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> t;
        ts.push_back(t);
        sum += t;
    }
    if (sum%2 == 0) limit = sum/2;
    else limit = sum/2+1;
    sort(ts.begin(), ts.end());
    cumul = 0;
    for (int i = 0; i < int(ts.size()); i++) {
        cumul += ts[i];
        if (cumul >= limit) {
            if (i < int(ts.size())-1) {
                cout << sum;
            }
            else cout << 2*(sum-cumul+ts[i]);
            return 0;
        }
    }
    return 0;
}
