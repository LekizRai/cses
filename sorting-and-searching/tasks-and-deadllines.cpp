#include <bits/stdc++.h>
using namespace std;

#define lli long long int


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lli n, duration, deadline, sum, cumul;
    cin >> n;
    vector<lli> durations;
    sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> duration >> deadline;
        durations.push_back(duration);
        sum += deadline;
    }
    sort(durations.begin(), durations.end());
    cumul = 0;
    for (auto &it: durations) {
        cumul += it;
        sum -= cumul;
    }
    cout << sum;
    return 0;
}


