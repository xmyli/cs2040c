// A0239072E
// Li Mingyuan
// Lab 4
// TA: Rezwan Arefin

#include <iostream>
#include <map>
#include <queue>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    map<int, int> freq;
    for (size_t i = 0; i < N; ++i) {
        int x, y;
        cin >> x;
        y = freq[x]+1;
        freq[x] = y;
    }

    priority_queue<int> count;
    map<int, int>::iterator it;
    for (it = freq.begin(); it != freq.end(); ++it) {
        count.push(it->second);
    }

    for (size_t i = 0; i < K; ++i) {
        int x = count.top();
        count.pop();
        count.push(x-1);
    }
    
    cout << count.top() << endl;
}