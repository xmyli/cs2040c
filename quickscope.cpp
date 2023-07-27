// A0239072E
// Li Mingyuan
// Lab 4
// TA: Rezwan Arefin

#include <iostream>
#include <string>
#include <map>
#include <stack>
#include <set>

using namespace std;

int main() {
    map<string, stack<string > > data;
    stack<set<string> > local;
    set<string> x;
    local.push(x);

    int N;
    cin >> N;
    for (size_t i = 0; i < N; i++) {
        string command;
        cin >> command;

        if (command == "{") {
            set<string> x;
            local.push(x);
        } else if (command == "}") {
            set<string>::iterator itr;
            for (itr = local.top().begin(); itr != local.top().end(); ++itr) {
                data[*itr].pop();
            }
            local.pop();
        } else if (command == "TYPEOF") {
            string name;
            cin >> name;
            if (data[name].empty()) {
                cout << "UNDECLARED" << endl;
            } else {
                cout << data[name].top() << endl;
            }
        } else if (command == "DECLARE") {
            string name, type;
            cin >> name >> type;
            if (local.top().find(name) == local.top().end()) {
                data[name].push(type);
                local.top().insert(name);
            } else {
                cout << "MULTIPLE DECLARATION" << endl;
                return 0;
            }
        }
    }
}