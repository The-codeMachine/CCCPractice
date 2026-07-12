#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

struct Node {
    int data;
    Node* parent;
    std::vector<Node*> children;
};

int main() {
    int n, q;
    std::cin >> n >> q;
    
    std::vector<Node> tree(n);
    for (int i = 0; i < n; ++i) {
        long r;
        std::cin >> r;
        tree[i].data = r;
    }

    for (int i = 1; i < n; ++i) {
        int a, b;
        std::cin >> a >> b;
        tree[a].children.push_back(&tree[b]);
        tree[b].parent = &tree[a];
    }

    for (int i = 0; i < q; ++i) {
        char query;
        int u, v;
        std::cin >> query >> u >> v;

        if (query == 'U') {
            tree[u].data = v;
        } else {
            // uses bfs to search the tree until we find the value
            std::queue<Node*> q;
            std::unordered_set<Node*> visited;
            
            Node* startNode = &tree[u];

            q.push(startNode);
            visited.insert(startNode);

            while (!q.empty()) {
                Node* current = q.front();
                q.pop();

                for (Node* child : current->children) {
                    if (child != nullptr && visited.find(child) == visited.end()) {
                        visited.insert(child);
                        q.push(child);
                    }
                }

                if (current->parent != nullptr) {
                    Node* parent = current->parent;
                    if (visited.find(parent) == visited.end()) {
                        visited.insert(parent);
                        q.push(parent);
                    }
                }
            }

        }
    }


    return 0;
}