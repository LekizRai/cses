#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n;
    set<int> num_lst;
    for (int i = 0; i < n; i++) {
        cin >> k;
        num_lst.insert(k);
    }
    cout << num_lst.size();
    return 0;
}
