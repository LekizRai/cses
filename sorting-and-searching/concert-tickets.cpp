#include <bits/stdc++.h>
using namespace std;


int ticket_search(vector<int> &h, vector<int> &next, vector<int> &prev, int &st, int &fi, int a)
{
    int n = h.size();
    int i, j, mid;
    int tmp;
    if (st < n && h[st] < 0) {
        while (st < n && h[st] < 0) {
            st = next[st];
        }
    }
    if (fi >= 0 && h[fi] < 0) {
        while (fi >= 0 && h[fi] < 0) {
            fi = prev[fi];
        }
    }
    if (st > fi) return -1;
    i = st;
    j = fi;
    while (i <= j) {
        mid = (i+j)/2;
        if (h[mid] < 0) {
            tmp = mid;
            while (h[mid] < 0) {
                mid = next[mid];
            }
            while (tmp != mid) {
                next[tmp]= mid;
                tmp = next[tmp];
            }
        }
        if (h[mid] < a) {
            i = next[mid];
        }
        else if (h[mid] >= a) {
            j = prev[mid];
        }
    }
    if (i >= n) {
        if (prev[j] >= 0) {
            next[prev[j]] = next[j];
        }
        if (next[j] < n) {
            prev[next[j]] = prev[j];
        }
        tmp = h[j];
        h[j] = -1;
        return tmp;
    }
    else {
        if (h[i] <= a) {
            if (prev[i] >= 0) {
                next[prev[i]] = next[i];
            }
            if (next[i] < n) {
                prev[next[i]] = prev[i];
            }
            tmp = h[i];
            h[i] = -1;
            return tmp;
        }
        else if (j >= 0 && h[j] <= a) {
            if (prev[j] >= 0) {
                next[prev[j]] = next[j];
            }
            if (next[j] < n) {
                prev[next[j]] = prev[j];
            }
            tmp = h[j];
            h[j] = -1;
            return tmp;
        }
        else return -1;
    }
}

int main()
{
    int n, m, t, st, fi;
    cin >> n >> m;
    vector<int> h(n, 0), next(n+1, 0), prev(n+1, 0);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
        next[i] = i+1;
        prev[i] = i-1;
    }
    sort(h.begin(), h.end());
    st = 0;
    fi = n-1;
    for (int i = 0; i < m; i++) {
        cin >> t;
        cout << ticket_search(h, next, prev, st, fi, t) << endl;
    }
    return 0;
}
