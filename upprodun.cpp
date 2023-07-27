#include <iostream>

int main() {
    int N, M;
    std::cin >> N >> M;
    
    int s = M/N;

    int L = M - s * N;

    for (int i = 0; i < L; i++) {
        for (int j = 0; j < s+1; j++) {
            std::cout << '*';
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < N - L; i++) {
        for (int j = 0; j < s; j++) {
            std::cout << '*';
        }
        std::cout << std::endl;
    }
}
