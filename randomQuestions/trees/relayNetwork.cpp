#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class HLD {
private:
    int n;

    vector<vector<int>> graph;

    // Tree information
    vector<int> parent;
    vector<int> depth;
    vector<int> subtreeSize;
    vector<int> heavyChild;

    // HLD information
    vector<int> head;
    vector<int> position;
    vector<int> nodeAtPosition;

    // Node values
    vector<int> value;

    int currentPos = 0;

    // Segment Tree
    vector<int> segTree;

public:
    HLD(int N) : n(N) {
        graph.resize(n);

        parent.assign(n, -1);
        depth.assign(n, 0);
        subtreeSize.assign(n, 0);
        heavyChild.assign(n, -1);

        head.resize(n);
        position.resize(n);
        nodeAtPosition.resize(n);

        value.resize(n);

        segTree.assign(4 * n, 0);
    }

    void setValue(int node, int v) {
        value[node] = v;
    }

    void addEdge(int a, int b) {
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

private:

    //-------------------------------------
    // DFS #1
    //-------------------------------------
    int dfs(int node, int par) {

        parent[node] = par;
        subtreeSize[node] = 1;

        int largest = 0;

        for (int child : graph[node]) {

            if (child == par)
                continue;

            depth[child] = depth[node] + 1;

            int size = dfs(child, node);

            subtreeSize[node] += size;

            if (size > largest) {
                largest = size;
                heavyChild[node] = child;
            }
        }

        return subtreeSize[node];
    }

    //-------------------------------------
    // DFS #2
    //-------------------------------------
    void decompose(int node, int chainHead) {

        head[node] = chainHead;

        position[node] = currentPos;
        nodeAtPosition[currentPos] = node;

        currentPos++;

        if (heavyChild[node] != -1)
            decompose(heavyChild[node], chainHead);

        for (int child : graph[node]) {

            if (child == parent[node])
                continue;

            if (child == heavyChild[node])
                continue;

            decompose(child, child);
        }
    }

    //-------------------------------------
    // Segment Tree
    //-------------------------------------

    void build(int idx, int left, int right) {

        if (left == right) {
            segTree[idx] = value[nodeAtPosition[left]];
            return;
        }

        int mid = (left + right) / 2;

        build(idx * 2, left, mid);
        build(idx * 2 + 1, mid + 1, right);

        segTree[idx] = max(segTree[idx * 2], segTree[idx * 2 + 1]);
    }

    void update(int idx, int left, int right, int pos, int val) {

        if (left == right) {
            segTree[idx] = val;
            return;
        }

        int mid = (left + right) / 2;

        if (pos <= mid)
            update(idx * 2, left, mid, pos, val);
        else
            update(idx * 2 + 1, mid + 1, right, pos, val);

        segTree[idx] = max(segTree[idx * 2], segTree[idx * 2 + 1]);
    }

    int query(int idx, int left, int right, int ql, int qr) {

        if (qr < left || right < ql)
            return INT_MIN;

        if (ql <= left && right <= qr)
            return segTree[idx];

        int mid = (left + right) / 2;

        return max(
            query(idx * 2, left, mid, ql, qr),
            query(idx * 2 + 1, mid + 1, right, ql, qr)
        );
    }

public:

    //-------------------------------------
    // Build everything
    //-------------------------------------

    void build() {

        dfs(0, -1);

        decompose(0, 0);

        build(1, 0, n - 1);
    }

    //-------------------------------------
    // Point Update
    //-------------------------------------

    void updateNode(int node, int val) {

        value[node] = val;

        update(
            1,
            0,
            n - 1,
            position[node],
            val
        );
    }

    //-------------------------------------
    // Path Query
    //-------------------------------------

    int queryPath(int a, int b) {

        int answer = INT_MIN;

        while (head[a] != head[b]) {

            if (depth[head[a]] < depth[head[b]])
                swap(a, b);

            answer = max(
                answer,
                query(
                    1,
                    0,
                    n - 1,
                    position[head[a]],
                    position[a]
                )
            );

            a = parent[head[a]];
        }

        if (depth[a] > depth[b])
            swap(a, b);

        answer = max(
            answer,
            query(
                1,
                0,
                n - 1,
                position[a],
                position[b]
            )
        );

        return answer;
    }
};

int main() {

    int N, Q;
    cin >> N >> Q;

    HLD tree(N);

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        tree.setValue(i, x);
    }

    for (int i = 0; i < N - 1; i++) {

        int a, b;
        cin >> a >> b;

        // Remove these if input is already 0-indexed
        --a;
        --b;

        tree.addEdge(a, b);
    }

    tree.build();

    while (Q--) {

        char type;
        cin >> type;

        if (type == 'U') {

            int u, x;
            cin >> u >> x;

            --u;

            tree.updateNode(u, x);

        } else {

            int u, v;
            cin >> u >> v;

            --u;
            --v;

            cout << tree.queryPath(u, v) << '\n';
        }
    }
}