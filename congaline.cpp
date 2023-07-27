// A0239072E
// Li Mingyuan
// Lab 4
// TA: Rezwan Arefin

#include <iostream>
#include <string>
#include <list>

using namespace std;

struct Person {
    string name;
    list<Person>::iterator partner;
};

int main() {
    int N, Q;
    cin >> N >> Q;

    list<Person> line;

    for (size_t i = 0; i < N; i++) {
        string name1, name2;
        cin >> name1 >> name2;

        Person p1;
        p1.name = name1;
        line.push_back(p1);

        Person p2;
        p2.name = name2;
        line.push_back(p2);

        prev(line.end(), 2) -> partner = prev(line.end());
        prev(line.end()) -> partner = prev(line.end(), 2);
    }
    
    list<Person>::iterator mic = line.begin();

    for (size_t i = 0; i < Q; i++) {
        char x;
        cin >> x;

        if (x == 'F') {
            --mic;
        }
        
        if (x == 'B') {
            ++mic;
        }
        
        if (x == 'R') {
            list<Person>::iterator newMicHolder;
            if (mic == prev(line.end())) {
                newMicHolder = line.begin();
            } else {
                newMicHolder = next(mic);
            }

            Person temp;
            temp.name = mic -> name;
            temp.partner = mic -> partner;
            line.erase(mic);
            line.push_back(temp);

            temp.partner -> partner = prev(line.end());

            mic = newMicHolder;
        }
        
        if (x == 'C') {
            list<Person>::iterator newMicHolder;
            if (mic == prev(line.end())) {
                newMicHolder = line.begin();
            } else {
                newMicHolder = next(mic);
            }

            Person temp;
            temp.name = mic -> name;
            temp.partner = mic -> partner;
            line.erase(mic);
            line.insert(next(temp.partner), temp);

            temp.partner -> partner = next(temp.partner);

            mic = newMicHolder;
        }
        
        if (x == 'P') {
            cout << mic -> partner -> name << endl;
        }
    }

    cout << endl;

    for (list<Person>::iterator i = line.begin(); i != line.end(); ++i) {
        cout << i -> name << endl;
    }
}
