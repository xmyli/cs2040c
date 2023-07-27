#include <iostream>
#include <unordered_set>

int main() {
    int N, Y;
    std::cin >> N >> Y;

    std::unordered_set<int> found;

    for (int i = 0; i < Y; i++) {
        int k;
        std::cin >> k;
        found.insert(k);
    }

    for (int i = 0; i < N; i++) {
        if (found.find(i) == found.end()) {
            std::cout << i << std::endl;
        }
    }
    std::cout << "Mario got " << found.size() << " of the dangerous obstacles." << std::endl;
}
