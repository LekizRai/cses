#include <bits/stdc++.h>
using namespace std;


bool a[200000];

int main()
{
    int n, k;
    cin >> n;
    for (int i = 0; i < n-1; i++) {
        cin >> k;
        a[k-1] = true;
    }
    for (int i = 0; i < n; i++) {
        if (!a[i]) {
            cout << i+1;
            return 0;
        }
    }
    return 0;
}
