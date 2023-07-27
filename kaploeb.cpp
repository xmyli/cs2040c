// A0239072E
// Li Mingyuan
// Lab 4
// TA: Rezwan Arefin

#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <sstream>

using namespace std;

struct Record {
    int id;
    int time;
    bool operator<(const Record& rhs) const {
        if (time != rhs.time) {
            return (time > rhs.time);
        } else {
            return (id > rhs.id);
        }
    }
};

int addTime(int initial, string add) {
    stringstream stream(add);
    string substring;
    getline(stream, substring, '.');
    int mins = stoi(substring);
    getline(stream, substring, '.');
    int secs = stoi(substring);
    return initial + 60*mins + secs;
}

int main() {
    int l, k, s;
    cin >> l >> k >> s;

    map<int, int> laps;
    map<int, int> durations;
    priority_queue<Record> finished;
    for (size_t i = 0; i < l; i++) {
        int runner_id;
        string lap_time;

        cin >> runner_id;
        cin >> lap_time;

        laps[runner_id] = laps[runner_id]+1;
        durations[runner_id] = addTime(durations[runner_id], lap_time);

        if (laps[runner_id] == k) {
            Record record;
            record.id = runner_id;
            record.time = durations[runner_id];
            finished.push(record);
        }
    }

    while (!finished.empty()) {
        cout << finished.top().id << endl;
        finished.pop();
    }
}
