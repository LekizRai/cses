#include <bits/stdc++.h>
using namespace std;


int main()
{
    int n;
    cin >> n;
    map<int, int> id;
    vector<int> k(n);
    for (int i = 0; i < n; i++) {
        cin >> k[i];
        id[k[i]] = -1;
    }
    long long int res = 0;
    long long int sum = 0;
    int prev_id = 0;
    for (int i = 0; i < n; i++) {
        if (id[k[i]] != -1) {
            res += sum*(sum+1)/2;
            sum -= id[k[i]]-prev_id;
            res -= sum*(sum-1)/2;
            for (int j = prev_id; j <= id[k[i]]-1; j++) {
                id[k[j]] = -1;
            }
            prev_id = id[k[i]]+1;
            id[k[i]] = i;
        }
        else {
            sum += 1;
            id[k[i]] = i;
        }
    }
    res += sum*(sum+1)/2;
    cout << res;
    return 0;
}

