#include <bits/stdc++.h>
using namespace std;

void do_swap(int disk_num, int source, int target)
{
    if (disk_num == 1) {
        cout << source << " " << target << endl;
        return;
    }
    do_swap(disk_num-1, source, 6-source-target);
    do_swap(1, source, target);
    do_swap(disk_num-1, 6-source-target, target);
}

int main()
{
    int n;
    cin >> n;
    int res = 1;
    for (int i = 0; i < n; i++) {
        res *= 2;
    }
    cout << res-1 << endl;
    do_swap(n, 1, 3);
    return 0;
}
