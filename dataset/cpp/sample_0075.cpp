#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

map<string, map<string, int>> distances;
vector<vector<string>> routes;
vector<string> best_route;

int calculate_cost(const vector<string>& route) {
    int cost = 0;
    for (size_t i = 0; i < route.size() - 1; ++i) {
        cost += distances[route[i]][route[i + 1]];
    }
    return cost;
}

vector<string> find_best_route(const vector<vector<string>>& routes) {
    vector<string> best = routes[0];
    int min_cost = calculate_cost(best);
    for (const auto& route : routes) {
        int cost = calculate_cost(route);
        if (cost < min_cost) {
            min_cost = cost;
            best = route;
        }
    }
    return best;
}

vector<string> optimize_supply_chain(map<string, map<string, int>>& data) {
    distances = data["distances"];
    routes = data["routes"];
    best_route = find_best_route(routes);
    return best_route;
}

int main() {
    map<string, map<string, int>> data = {
        {"distances", {
            {"A", {{"B", 10}, {"C", 15}}},
            {"B", {{"A", 10}, {"C", 35}}},
            {"C", {{"A", 15}, {"B", 35}}}
        }},
        {"routes", {
            {"A", "B", "C"},
            {"A", "C", "B"}
        }}
    };

    best_route = optimize_supply_chain(data);
    for (const auto& city : best_route) {
        cout << city << " ";
    }
    cout << endl;
    return 0;
}