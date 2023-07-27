// A0239072E
// Li Mingyuan
// Lab 4
// TA: Rezwan Arefin

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

struct Ping {
    int p, x, y, t;
};

struct Pair {
    int a, b;
};

bool comparePings(Ping const& lhs, Ping const& rhs) {
    if (lhs.t < rhs.t) {
        return true;
    }
    return false;
}

bool comparePairs(Pair const& lhs, Pair const& rhs) {
    if (lhs.a < rhs.a) {
        return true;
    } else if (lhs.a == rhs.a) {
        if (lhs.b < rhs.b) {
            return true;
        }
        return false;
    }
    return false;
}

int main() {
    vector<Ping> pings;
    vector<Pair> pairs;

    int P, N;
    cin >> P >> N;

    for (size_t i = 0; i < N; i++) {
        int p, x, y, t;
        cin >> p >> x >> y >> t;
        Ping ping;
        ping.p = p;
        ping.x = x;
        ping.y = y;
        ping.t = t;
        pings.push_back(ping);
    }
    
    sort(pings.begin(), pings.end(), &comparePings);

    for (size_t i = 1; i < pings.size(); i++) {
        for (size_t j = max(0, int(i-4)); j < i ; j++) {
            float dist = sqrt(pow(pings[i].x - pings[j].x, 2)+pow(pings[i].y - pings[j].y, 2));
            int diff_t = pings[i].t - pings[j].t;
            if (dist <= 1000 && diff_t <= 10) {
                Pair pair;
                pair.a = min(pings[i].p, pings[j].p);
                pair.b = max(pings[i].p, pings[j].p);
                pairs.push_back(pair);
            }
        }
    }

    sort(pairs.begin(), pairs.end(), &comparePairs);

    vector<Pair> noDuplicates;
    for (size_t i = 0; i < pairs.size(); i++) {
        bool isDuplicate = false;
        for (size_t j = 0; j < noDuplicates.size(); j++) {
            if (pairs[i].a == noDuplicates[j].a && pairs[i].b == noDuplicates[j].b) {
                isDuplicate = true;
            }
        }
        if (!isDuplicate && pairs[i].a != pairs[i].b) {
            noDuplicates.push_back(pairs[i]);
        }
    }

    cout << noDuplicates.size() << endl;
    for (size_t i = 0; i < noDuplicates.size(); i++) {
        cout << noDuplicates[i].a << " " << noDuplicates[i].b << endl;
    }
}
