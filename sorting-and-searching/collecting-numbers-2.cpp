#include <bits/stdc++.h>
using namespace std;


int main()
{
    int n, m, a, b, id, dif;
    cin >> n >> m;
    vector<int> x(n+2);
    vector<int> _x(n);
    for (int i = 0; i < n; i++) {
        cin >> id;
        x[id] = i;
        _x[i] = id;
    }
    x[0] = -1;
    x[n+1]= 1000000;
    int cur_id = -1;
    int init_res = 1;
    for (int i = 0; i < n+2; i++) {
        if (cur_id > x[i]) {
            init_res += 1;
        }
        cur_id = x[i];
    }
    while (m--) {
        cin >> a >> b;

        a -= 1; b -= 1;

        if (_x[a] > _x[b]) {
            swap(a, b);
        }

        dif = 0;
        if (_x[b] == _x[a]+1) {
            if (x[_x[a]-1] >= x[_x[a]]) dif += 1;
            if (x[_x[a]] >= x[_x[a]+1]) dif += 1;
            if (x[_x[a]+1] >= x[_x[a]+2]) dif += 1;

            // swap two indices in x
            swap(x[_x[a]], x[_x[b]]);

            // swap two indices in _x
            swap(_x[a], _x[b]);

            if (x[_x[b]-1] >= x[_x[b]]) dif -= 1;
            if (x[_x[b]] >= x[_x[b]+1]) dif -= 1;
            if (x[_x[b]+1] >= x[_x[b]+2]) dif -= 1;

            init_res -= dif;
            cout << init_res << endl;
        }
        else {
            if (x[_x[a]-1] >= x[_x[a]]) dif += 1;
            if (x[_x[a]] >= x[_x[a]+1]) dif += 1;
            if (x[_x[b]-1] >= x[_x[b]]) dif += 1;
            if (x[_x[b]] >= x[_x[b]+1]) dif += 1;

            // swap two indices in x
            swap(x[_x[a]], x[_x[b]]);

            // swap two indices in _x
            swap(_x[a], _x[b]);

            if (x[_x[a]-1] >= x[_x[a]]) dif -= 1;
            if (x[_x[a]] >= x[_x[a]+1]) dif -= 1;
            if (x[_x[b]-1] >= x[_x[b]]) dif -= 1;
            if (x[_x[b]] >= x[_x[b]+1]) dif -= 1;
            init_res -= dif;
            cout << init_res << endl;
        }
    }
    return 0;
}
