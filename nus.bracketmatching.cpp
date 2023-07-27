// A0239072E
// Li Mingyuan
// Lab 4
// TA: Rezwan Arefin

#include <iostream>
#include <stack>

using namespace std;

int main() {
    int n;
    cin >> n;
    stack<char> s;
    for (size_t i = 0; i < n; i++) {
        char x;
        cin >> x;
        if (x == '(' || x == '[' || x == '{') {
            s.push(x);
        } else if (s.size() > 0) {
            if (x == ')' && s.top() == '(') {
                s.pop();
            } else if (x == ']' && s.top() == '[') {
                s.pop();
            } else if (x == '}' && s.top() == '{') {
                s.pop();
            }
        } else {
            s.push('!');
        }
    }

    if (s.size() != 0) {
        cout << "Invalid" << endl;
    } else {
        cout << "Valid" << endl;
    }
}