// GLALL
#include <iostream>
#include <list>
#include <string>
#include <map>

using namespace std;

struct CardSet {
    int value, count;
};

int main() {
    int N;
    cin >> N;

    list<CardSet> deck;
    map<int, int> counts;

    for (size_t i = 0; i < N; i++) {
        string command;
        cin >> command;
        if (command == "PUT_TOP") {
            int X, Y;
            cin >> X >> Y;
            CardSet cards;
            cards.value = Y;
            cards.count = X;
            deck.push_front(cards);
            counts[Y] = counts[Y] + X;
        } else if (command == "PUT_BOTTOM") {
            int X, Y;
            cin >> X >> Y;
            CardSet cards;
            cards.value = Y;
            cards.count = X;
            deck.push_back(cards);
            counts[Y] = counts[Y] + X;
        } else if (command == "REMOVE_TOP") {
            int Z;
            cin >> Z;
            while (Z > 0) {
                if (deck.front().count <= Z) {
                    Z-=deck.front().count;
                    counts[deck.front().value] = counts[deck.front().value] - deck.front().count;
                    deck.pop_front();
                } else {
                    CardSet newSet;
                    newSet.count = deck.front().count-Z;
                    newSet.value = deck.front().value;
                    counts[deck.front().value] = counts[deck.front().value] - Z;
                    Z = 0;
                    deck.pop_front();
                    deck.push_front(newSet);
                }
            }
        } else if (command == "REMOVE_BOTTOM") {
            int Z;
            cin >> Z;
            while (Z > 0) {
                if (deck.back().count <= Z) {
                    Z-=deck.back().count;
                    counts[deck.back().value] = counts[deck.back().value] - deck.back().count;
                    deck.pop_back();
                } else {
                    CardSet newSet;
                    newSet.count = deck.back().count-Z;
                    newSet.value = deck.back().value;
                    counts[deck.back().value] = counts[deck.back().value] - Z;
                    Z = 0;
                    deck.pop_back();
                    deck.push_back(newSet);
                }
            }
        }

        int max = -1;
        int max_value;
        map<int, int>::iterator itr;
        for (itr = counts.begin(); itr != counts.end(); itr++) {
            if (itr->second > max) {
                max = itr->second;
                max_value = itr->first;
            }
        }
        cout << max_value << endl;
    }
}