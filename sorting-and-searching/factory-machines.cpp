#include <bits/stdc++.h>
using namespace std;

#define lli long long int

lli find_time(vector<lli> &ks, lli t) {
    lli i, j, mid, sum;
    i = 0; j = *prev(ks.end())*t;
    while (i <= j) {
        mid = (i+j)/2;

        // compute sum
        sum = 0;
        for (int id = 0; id < int(ks.size()); id++) {
            sum += mid/ks[id];
            if (sum >= t) break;
        }

        if (sum >= t) {
            j = mid-1;
        }
        else i = mid+1;
    }
    return i;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lli n, t, k;
    cin >> n >> t;
    vector<lli> ks;
    for (int i = 0; i < n; i++) {
        cin >> k;
        ks.push_back(k);
    }
    sort(ks.begin(), ks.end());
    cout << find_time(ks, t);
    return 0;
}

