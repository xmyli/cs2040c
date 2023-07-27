#include <iostream>
#include <stack>
#include <string>
#include <vector>

bool check(std::string s) {
    std::stack<char> st;
    for (char c : s) {
        if (c == '$' || c == '|' || c == '*') {
            st.push(c);
        } else if (c == 'b') {
            if (st.size() > 0 && st.top() == '$') {
                st.pop();
            } else {
                return false;
            }
        } else if (c == 't') {
            if (st.size() > 0 && st.top() == '|') {
                st.pop();
            } else {
                return false;
            }
        } else if (c == 'j') {
            if (st.size() > 0 && st.top() == '*') {
                st.pop();
            } else {
                return false;
            }
        }
    }
    return st.size() == 0;
}

int main() {
    int n;
    std::cin >> n;

    std::vector<bool> ans;

    for (int i = 0; i < n; i++) {
        std::string s;
        std::cin >> s;

        ans.push_back(check(s));
    }

    for (bool a : ans) {
        if (a) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    }
}
