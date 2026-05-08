#include <bits/stdc++.h>
using namespace std;


int main()
{
    int t;
    long long int x, y, res;
    cin >> t;
    while (t--) {
        cin >> y >> x;
        res = 1;
        if (y >= x) {
            res += y*(y-1);
            if (y%2 == 1) {
                res += x-y;
            }
            else {
                res += y-x;
            }
        }
        else {
            res += x*(x-1);
            if (x%2 == 1) {
                res += x-y;
            }
            else {
                res += y-x;
            }
        }
        cout << res << endl;
    }
    return 0;
}
