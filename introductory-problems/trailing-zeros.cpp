#include <bits/stdc++.h>
using namespace std;


long int find_div5_nearest(long int n)
{
    if (n%10 >= 5) {
        return n - (n%10 - 5);
    }
    else {
        return n - (n%10);
    }
}

int main()
{
    long int n;
    long int res = 0;
    long int inc = 0;
    cin >> n;
    inc = n;
    do {
        inc = find_div5_nearest(inc)/5;
        res += inc;
    } while (inc >= 5);
    cout << res;
    return 0;
}
