#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int res = 6;
    long long int n;
    cin >> n;
    if (n == 1) {
        cout << 0;
    }
    else {
        cout << 0 << "\n" << 6 << "\n";
        for (long long int i = 3; i <= n; i++) {
            res = (i-1)*(i-1)*(i-1) - 4*(i-1) + 6 + (i-1)*i*i - 4*i + 6 + res + ((i-2)*(i-1))/2 + ((i-1)*i)/2;
            cout << res << "\n";
        }
    }
    return 0;
}
