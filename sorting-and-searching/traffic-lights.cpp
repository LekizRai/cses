#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int x, n, p;
    cin >> x >> n;
    set<int> pos;
    multiset<int> res;
    set<int>::iterator low, up;
    multiset<int>::iterator it;
    pos.insert(0); pos.insert(x);
    res.insert(x);
    for (int i = 0; i < n; i++) {
        cin >> p;
        up = pos.upper_bound(p);
        low = prev(up);
        it = res.find((*up)-(*low));
        res.erase(it);
        res.insert((*up)-p); res.insert(p-(*low)); pos.insert(p);
        cout << *res.rbegin() << " ";
    }

    return 0;
}
