#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    if (n == 1) {
        cout << 1;
        return 0;
    }
    vector<int> next(n), prev(n);
    for (int i = 0; i < n-1; i++) {
        next[i] = i+1;
    }
    next[n-1] = 0;
    for (int i = 1; i < n; i++) {
        prev[i] = i-1;
    }
    prev[0] = n-1;
    int id = 1;
    while (n--) {
        cout << id+1 << " ";
        next[prev[id]] = next[id];
        prev[next[id]] = prev[id];
        id = next[next[id]];
    }
    return 0;
}
