// A0239072E
// Li Mingyuan
// Lab 4
// TA: Rezwan Arefin

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int indexOfFirstGreaterThanOrEqual(int x, vector<int>& in, int from, int to) {
    if (x > in[in.size()-1] || from >= in.size()) {
        return -1;
    }
    if (in[from] >= x) {
        return from;
    }
    int middle = (from + to)/2;
    if (in[middle] >= x) {
        return indexOfFirstGreaterThanOrEqual(x, in, from, middle-1);
    } else {
        return indexOfFirstGreaterThanOrEqual(x, in, middle+1, to);
    }
}

int indexOfLastSmallerThanOrEqual(int x, vector<int>& in, int from, int to) {
    if (x < in[0] || to < 0) {
        return -1;
    }
    if (in[to] <= x) {
        return to;
    }
    int middle = (from + to)/2;
    if (in[middle] <= x) {
        return indexOfLastSmallerThanOrEqual(x, in, middle+1, to);
    } else {
        return indexOfLastSmallerThanOrEqual(x, in, from, middle-1);
    }
}

int main() {
    size_t N;
    cin >> N;

    vector<int> cards(N);
    for (size_t i = 0; i < N; i++) {
        int x;
        cin >> x;
        cards[i] = x;
    }

    sort(cards.begin(), cards.end());

    size_t Q;
    cin >> Q;

    for (size_t i = 0; i < Q; i++) {
        int l, r;
        cin >> l >> r;
        int indexL = indexOfFirstGreaterThanOrEqual(l, cards, 0, cards.size()-1);
        int indexR = indexOfLastSmallerThanOrEqual(r, cards, 0, cards.size()-1);
        
        if (indexL == -1 || indexR == -1) {
            cout << 0 << endl;
        } else {
            cout << indexR-indexL+1 << endl;
        }
    }
}