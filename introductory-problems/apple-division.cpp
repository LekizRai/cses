#include <bits/stdc++.h>
using namespace std;


long long int cal_min_dif(long long int p[], int n, long long int sum, int id, long long int res) {
    if (id == n) {
        return min(abs(sum-2*res),
                   abs(sum-2*(res+p[id-1])));
    }
    return min(cal_min_dif(p, n, sum, id+1, res),
               cal_min_dif(p, n, sum, id+1, res+p[id-1]));
}

int main()
{
    int n;
    long long int sum, p[30];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    sum = 0;
    for (int i = 0; i < n; i++) {
        sum += p[i];
    }
    cout << cal_min_dif(p, n, sum, 1, 0);
    return 0;
}
