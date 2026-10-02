#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <utility>

using namespace std;

struct Node {
    int x, y;
    Node(int x, int y) : x(x), y(y) {}
    bool operator==(const Node& other) const {
        return x == other.x && y == other.y;
    }
};

struct NodeHash {
    size_t operator()(const Node& node) const {
        return hash<int>()(node.x) ^ (hash<int>()(node.y) << 1);
    }
};

struct NodeCompare {
    bool operator()(const pair<Node, int>& a, const pair<Node, int>& b) const {
        return a.second > b.second;
    }
};

vector<Node> grid_2d_graph(int rows, int cols) {
    vector<Node> nodes;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            nodes.emplace_back(i, j);
        }
    }
    return nodes;
}

vector<Node> shortest_path(const vector<Node>& nodes, const Node& start, const Node& end) {
    priority_queue<pair<Node, int>, vector<pair<Node, int>>, NodeCompare> openSet;
    unordered_map<Node, int, NodeHash> gScore;
    unordered_map<Node, Node, NodeHash> cameFrom;
    openSet.emplace(start, 0);
    gScore[start] = 0;

    while (!openSet.empty()) {
        Node current = openSet.top().first;
        openSet.pop();

        if (current == end) {
            vector<Node> path;
            Node current = end;
            while (current != start) {
                path.push_back(current);
                current = cameFrom[current];
            }
            path.push_back(start);
            reverse(path.begin(), path.end());
            return path;
        }

        for (const auto& dir : vector<pair<int, int>>{{0, 1}, {1, 0}, {0, -1}, {-1, 0}}) {
            Node neighbor(current.x + dir.first, current.y + dir.second);
            if (find(nodes.begin(), nodes.end(), neighbor) != nodes.end()) {
                int tentativeGScore = gScore[current] + 1;
                if (gScore.find(neighbor) == gScore.end() || tentativeGScore < gScore[neighbor]) {
                    cameFrom[neighbor] = current;
                    gScore[neighbor] = tentativeGScore;
                    openSet.emplace(neighbor, tentativeGScore);
                }
            }
        }
    }
    return {};
}

int main() {
    vector<Node> g = grid_2d_graph(10, 10);
    Node start(0, 0);
    Node end(9, 9);
    vector<Node> path = shortest_path(g, start, end);
    while (true) {
        for (const auto& node : path) {
            cout << "(" << node.x << ", " << node.y << ")" << endl;
        }
    }
    return 0;
}