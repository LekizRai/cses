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

// Fenwick tree
int get_sum(vector<int> &fenwick, int ub)
{
    int sum = 0;
    while (ub >= 0) {
        sum += fenwick[ub];
        ub = (ub&(ub+1))-1;
    }
    return sum;
}

void increase(vector<int> &fenwick, int i, int a)
{
    for (; i < int(fenwick.size()); i = i|(i+1)) {
        fenwick[i] += a;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, x, y, id, sum, cur_fi;
    Event event;
    pair<int, int> interval;
    cin >> n;
    vector<Event> events;
    vector<pair<int, int>> intervals;
    set<int> uniq_sts;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        uniq_sts.insert(x);
        interval.first = x; interval.second = y;
        intervals.push_back(interval);
        event.id = i;
        event.t = x; event.type = 0;
        events.push_back(event);
        event.t = y; event.type = 1;
        events.push_back(event);
    }
    map<int, int> t2id;
    id = 0;
    for (auto &it: uniq_sts) {
        t2id[it] = id;
        id += 1;
    }
    sort(events.begin(), events.end(), c);

    // find contained numbers
    vector<int> fenwick(int(uniq_sts.size()), 0);
    vector<int> contained_num(n, 0);
    vector<Event> fi_events;
    cur_fi = -1;
    for (int i = 0; i < int(events.size()); i++) {
        event = events[i];
        if (event.type == 0) {
            increase(fenwick, t2id[event.t], 1);
        }
        else {
            if (event.t != cur_fi) {
                for (auto &it: fi_events) {
                    contained_num[it.id] = get_sum(fenwick, t2id[intervals[it.id].first])-1;
                }
                for (auto &it: fi_events) {
                    increase(fenwick, t2id[intervals[it.id].first], -1);
                }
                fi_events.clear();
                cur_fi = event.t;
            }
            fi_events.push_back(event);
        }
    }
    for (auto &it: fi_events) {
        contained_num[it.id] = get_sum(fenwick, t2id[intervals[it.id].first])-1;
    }

    // find containing numbers
    vector<int> containing_num(n, 0);
    fi_events.clear();
    fill(fenwick.begin(), fenwick.end(), 0);
    sum = 0;
    cur_fi = -1;
    for (int i = 0; i < int(events.size()); i++) {
        event = events[i];
        if (event.type == 1) {
            if (event.t != cur_fi) {
                for (auto &it: fi_events) {
                    containing_num[it.id] = sum-get_sum(fenwick, t2id[intervals[it.id].first]-1)-1;
                }
                fi_events.clear();
                cur_fi = event.t;
            }
            fi_events.push_back(event);
            increase(fenwick, t2id[intervals[event.id].first], 1);
            sum += 1;
        }
    }
    for (auto &it: fi_events) {
        containing_num[it.id] = sum-get_sum(fenwick, t2id[intervals[it.id].first]-1)-1;
    }

    // outputs
    for (auto &it: containing_num) {
        cout << it << " ";
    }
    cout << endl;
    for (auto &it: contained_num) {
        cout << it << " ";
    }
    return 0;
}
