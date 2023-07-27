#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> answers;

    for (int i = 0; i < n; i++) {
        int m, r; // m = number of nodes, r = number of edges
        std::cin >> m >> r;

        std::unordered_set<int> vertices;
        for (int j = 0; j < m; j++) {
            vertices.insert(j);
        }

        std::unordered_map<int, std::unordered_set<int> > adj_list;
        for (int j = 0; j < r; j++) {
            int a, b;
            std::cin >> a >> b;
            
            if (adj_list.find(a) == adj_list.end()) {
                adj_list[a] = std::unordered_set<int>();
            }
            if (adj_list.find(b) == adj_list.end()) {
                adj_list[b] = std::unordered_set<int>();
            }

            adj_list[a].insert(b);
            adj_list[b].insert(a);
        }

        int num_components = 0;
        while (!vertices.empty()) {
            std::queue<int> q;
            q.push(*vertices.begin());
            vertices.erase(q.front());

            while (!q.empty()) {
                int node = q.front();
                q.pop();
                std::unordered_set<int> neighbors = adj_list[node];
                
                std::unordered_set<int>::iterator it;
                for (it = neighbors.begin(); it != neighbors.end(); it++) {
                    if (vertices.find(*it) != vertices.end()) {
                        q.push(*it);
                        vertices.erase(*it);
                    }
                }
            }
            num_components++;
        }

        answers.push_back(num_components-1);
    }

    for (int i = 0; i < answers.size(); i++) {
        std::cout << answers[i] << std::endl;
    }
}