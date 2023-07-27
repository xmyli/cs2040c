// A0239072E
// Li Mingyuan
// Lab 4
// TA: Rezwan Arefin

#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;

    multimap<int, bool> mmap;
    for (size_t i = 0; i < N; i++) {
        int x;
        cin >> x;
        mmap.insert(pair<int, bool>(x, true));
    }

    for (size_t i = 0; i < Q; i++) {
        int T, D;
        cin >> T >> D;
        if (T == 1) {
            multimap<int, bool>::iterator itr = mmap.upper_bound(D);
            if (itr != mmap.end()) {
                int value = itr->first;
                mmap.erase(itr);
                cout << value << endl;
            } else {
                cout << -1 << endl;
            }
        } else {
            multimap<int, bool>::iterator itr = mmap.upper_bound(D);
            if (itr != mmap.begin()) {
                int value = prev(itr)->first;
                mmap.erase(prev(itr));
                cout << value << endl;
            } else {
                cout << -1 << endl;
            }
        }
    }
}