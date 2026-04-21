#include <bits/stdc++.h>
using namespace std;

#define lli long long int


bool find_val(vector<lli> &cumul, lli val, int lb, int ub)
{
    int mid;
    while (lb <= ub) {
        mid = (lb+ub)/2;
        if (cumul[mid] > val) {
            ub = mid-1;
        }
        else if (cumul[mid] < val) {
            lb = mid+1;
        }
        else return true;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lli n, x, res;
    cin >> n >> x;
    vector<lli> a(n);
    vector<lli> cumul(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i == 0) cumul[i] = a[i];
        else cumul[i] = cumul[i-1]+a[i];
    }
    res = 0;
    if (find_val(cumul, x, 0, n-1)) {
        res += 1;
    }
    for (int i = 0; i < n; i++) {
        if (find_val(cumul, cumul[i]+x, i+1, n-1)) {
            res += 1;
        }
    }
    cout << res;
    return 0;
}
