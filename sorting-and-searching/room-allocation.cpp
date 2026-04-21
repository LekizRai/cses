#include <bits/stdc++.h>
using namespace std;

struct Event
{
    int t;
    int type; // 0 for start and 1 for end
    int id;
};

bool c(Event x, Event y)
{
    if (x.t <= y.t) {
        if (x.t < y.t) return true;
        else {
            if (x.type < y.type) return true;
            else return false;
        }
    }
    else return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, a, b, id;
    cin >> n;
    vector<pair<int, int>> intervals;
    pair<int, int> interval;
    vector<Event> events;
    Event event;
    set<int> fis;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        fis.insert(b);
        interval.first = a; interval.second = b;
        intervals.push_back(interval);
        event.id = i;
        event.t = a; event.type = 0;
        events.push_back(event);
        event.t = b; event.type = 1;
        events.push_back(event);
    }
    map<int, int> t2id;
    id = 0;
    for (auto &it: fis) {
        t2id[it] = id;
        id += 1;
    }
    sort(events.begin(), events.end(), c);

    // assign rooms
    int total_room = 0;
    vector<int> assigned_room(n, 0);
    vector<vector<int>> id2rooms(int(fis.size()));
    fis.clear();
    for (auto &event: events) {
        if (event.type == 0) {
            auto pos = fis.lower_bound(event.t);
            if (pos == fis.begin()) {
                total_room += 1;
                assigned_room[event.id] = total_room;
            }
            else {
                assigned_room[event.id] = id2rooms[t2id[*prev(pos)]].back();
                id2rooms[t2id[*prev(pos)]].pop_back();
                if (id2rooms[t2id[*prev(pos)]].empty()) {
                    fis.erase(prev(pos));
                }
            }
            fis.insert(intervals[event.id].second);
            id2rooms[t2id[intervals[event.id].second]].push_back(assigned_room[event.id]);
        }
    }

    // outputs
    cout << total_room << endl;
    for (auto &it: assigned_room) {
        cout << it << " ";
    }
    return 0;
}
