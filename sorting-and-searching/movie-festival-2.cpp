#include <bits/stdc++.h>
using namespace std;


struct Event
{
    int t;
    int dual_t;
    int type;
};

bool c(Event x, Event y)
{
    if (x.t < y.t) return true;
    else if (x.t > y.t) return false;
    else {
        if (x.type <= y.type) return true;
        return false;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k, res;
    cin >> n >> k;
    Event event;
    vector<Event> events;
    for (int i = 0; i < n; i++) {
        cin >> event.t >> event.dual_t;
        event.type = 1;
        events.push_back(event);
        swap(event.t, event.dual_t);
        event.type = 0;
        events.push_back(event);
    }
    sort(events.begin(), events.end(), c);
    res = n;
    multiset<int> fis;
    for (auto &it: events) {
        if (it.type == 1) {
            if (int(fis.size()) < k) {
                fis.insert(it.dual_t);
            }
            else {
                if ((*fis.rbegin()) > it.dual_t) {
                    fis.erase(prev(fis.end()));
                    fis.insert(it.dual_t);
                }
                res -= 1;
            }
        }
        else {
            if (fis.find(it.t) != fis.end()) {
                fis.erase(it.t);
            }
        }
    }
    cout << res;
    return 0;
}
