#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int N;
    cin >> N;

    priority_queue<int, vector<int>, greater<int> > not_included; // <difficulty of vertex, vertex index>
    priority_queue<int, vector<int>, greater<int> > included;

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        not_included.push(x);
    }

    int src = not_included.top(); not_included.pop();
    included.push(src);

    long sum = 0;

    while (!not_included.empty()) {
        int min_not_included = not_included.top();
        int min_included = included.top();
        
        not_included.pop();
        included.push(min_not_included);

        sum += (min_not_included + min_included);
    }

    cout << sum << endl;
}