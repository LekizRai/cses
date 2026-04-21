#include <bits/stdc++.h>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k, id, step, row, col;
    cin >> n >> k;
    int sqrt_n = int(sqrt(n))+1;
    vector<vector<int>> a(sqrt_n, vector<int> (0));
    id = 0;
    for (int i = 1; i <= n; i++) {
        a[id].push_back(i);
        if (i%sqrt_n == 0) {
            id += 1;
        }
    }
    row = 0; col = 0;
    for (int i = n; i >= 1; i--) {
        step = k%i;

        // search for the desired eliminated element
        if (col+step >= int(a[row].size())) {
            step -= int(a[row].size())-col;
            col = 0;
            row = (row+1)%sqrt_n;
            while (step >= int(a[row].size())) {
                step -= int(a[row].size());
                row = (row+1)%sqrt_n;
            }
        }
        cout << a[row][col+step] << " ";
        a[row].erase(a[row].begin()+col+step);

        // modify row and col
        if (i == 1) break;
        if (col+step >= int(a[row].size())) {
            row = (row+1)%sqrt_n;
            while (int(a[row].size()) <= 0) {
                row = (row+1)%sqrt_n;
            }
            col = 0;
        }
        else {
            col += step;
        }
    }
    return 0;
}

