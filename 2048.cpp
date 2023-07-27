#include <iostream>
#include <list>

using namespace std;

int main() {
    int state[4][4];
    for (size_t i = 0; i < 4; i++) {
        for (size_t j = 0; j < 4; j++) {
            cin >> state[i][j];
        }
    }

    // i: top to bottom
    // j: left to right
    
    int action;
    cin >> action;

    if (action == 0) {
        for (int i = 0; i < 4; i++) {
            list<int> values;
            for (int j = 0; j < 4; j++) {
                if (state[i][j] != 0) {
                    values.push_back(state[i][j]);
                }
            }

            list<int> new_values;

            list<int>::iterator it;
            for (it = values.begin(); it != values.end(); it++) {
                if (it != values.begin() && *it == *prev(it) && *it == new_values.back()) {
                    new_values.pop_back();
                    new_values.push_back(2*(*it));
                } else {
                    new_values.push_back(*it);
                }
            }

            for (int j = 0; j < 4; j++) {
                if (new_values.size() != 0) {
                    state[i][j] = new_values.front();
                    new_values.pop_front();
                } else {
                    state[i][j] = 0;
                }
            }
        }
    }

    if (action == 1) {
        for (int j = 0; j < 4; j++) {
            list<int> values;
            for (int i = 0; i < 4; i++) {
                if (state[i][j] != 0) {
                    values.push_back(state[i][j]);
                }
            }

            list<int> new_values;

            list<int>::iterator it;
            for (it = values.begin(); it != values.end(); it++) {
                if (it != values.begin() && *it == *prev(it) && *it == new_values.back()) {
                    new_values.pop_back();
                    new_values.push_back(2*(*it));
                } else {
                    new_values.push_back(*it);
                }
            }

            for (int i = 0; i < 4; i++) {
                if (new_values.size() != 0) {
                    state[i][j] = new_values.front();
                    new_values.pop_front();
                } else {
                    state[i][j] = 0;
                }
            }
        }
    }

    if (action == 2) {
        for (int i = 0; i < 4; i++) {
            list<int> values;
            for (int j = 3; j >= 0; j--) {
                if (state[i][j] != 0) {
                    values.push_back(state[i][j]);
                }
            }

            list<int> new_values;

            list<int>::iterator it;
            for (it = values.begin(); it != values.end(); it++) {
                if (it != values.begin() && *it == *prev(it) && *it == new_values.back()) {
                    new_values.pop_back();
                    new_values.push_back(2*(*it));
                } else {
                    new_values.push_back(*it);
                }
            }

            for (int j = 3; j >= 0; j--) {
                if (new_values.size() != 0) {
                    state[i][j] = new_values.front();
                    new_values.pop_front();
                } else {
                    state[i][j] = 0;
                }
            }
        }
    }

    if (action == 3) {
        for (int j = 0; j < 4; j++) {
            list<int> values;
            for (int i = 3; i >= 0; i--) {
                if (state[i][j] != 0) {
                    values.push_back(state[i][j]);
                }
            }

            list<int> new_values;

            list<int>::iterator it;
            for (it = values.begin(); it != values.end(); it++) {
                if (it != values.begin() && *it == *prev(it) && *it == new_values.back()) {
                    new_values.pop_back();
                    new_values.push_back(2*(*it));
                } else {
                    new_values.push_back(*it);
                }
            }

            for (int i = 3; i >= 0; i--) {
                if (new_values.size() != 0) {
                    state[i][j] = new_values.front();
                    new_values.pop_front();
                } else {
                    state[i][j] = 0;
                }
            }
        }
    }

    for (size_t i = 0; i < 4; i++) {
        for (size_t j = 0; j < 4; j++) {
            cout << state[i][j] << " ";
        }
        cout << endl;
    }
}