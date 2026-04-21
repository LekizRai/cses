#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<long long int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    sort(x.begin(), x.end());
    long long int sum = 0;
    for (int i = 0; i < n; i++) {
        if (sum < x[i]-1) {
            cout << sum+1;
            return 0;
        }
        sum += x[i];
    }
    cout << sum+1;
    return 0;
}
