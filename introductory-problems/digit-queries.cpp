#include <bits/stdc++.h>
using namespace std;


int main()
{
    int q;
    long long int k, inc, num, r;
    cin >> q;
    while (q--) {
        cin >> k;
        if (k <= 9) {
            cout << k << endl;
        }
        else {
            inc = 9;
            for (long long int i = 1; i <= 20; i++) {
                if (k - inc*i > 0) {
                    k -= inc*i;
                    inc *= 10;
                }
                else {
                    num = ((k-1)/i)+(inc/9);
                    r = (k-1)%i+1;
                    for (int j = 0; j < i-r; j++) {
                        num /= 10;
                    }
                    cout << num%10 << endl;
                    break;
                }
            }
        }
    }
    return 0;
}
