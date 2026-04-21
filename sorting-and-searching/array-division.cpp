#include <bits/stdc++.h>
using namespace std;

#define lli long long int


bool check_partition(vector<lli> &x, lli ub, int max_partition)
{
    lli sum = 0;
    int partition_num = 1;
    for(auto &it: x) {
        if (sum+it > ub) {
            if (sum == 0) return false;
            else {
                sum = it;
                partition_num += 1;
            }
        }
        else sum += it;
    }
    if (partition_num > max_partition || sum > ub) return false;
    return true;
}

lli find_val(vector<lli> &x, lli lb, lli ub, int max_partition)
{
    lli mid;
    while (lb <= ub) {
        mid = (lb+ub)/2;
        if (check_partition(x, mid, max_partition)) {
            ub = mid-1;
        }
        else lb = mid+1;
    }
    return lb;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<lli> x(n);
    lli sum, mx;
    sum = 0;
    mx = 0;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        sum += x[i];
        mx = max(mx, x[i]);
    }
    cout << find_val(x, mx, sum, k);
    return 0;
}
