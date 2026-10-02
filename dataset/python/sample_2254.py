import random

def calculate_cost(route, distances):
    cost = 0.0
    for i in range(len(route) - 1):
        cost += distances[route[i]][route[i + 1]]
    return cost

def optimize_route(start, nodes, distances):
    route = [start] + random.sample(nodes, len(nodes))
    cost = calculate_cost(route, distances)
    while True:
        for i in range(1, len(route) - 1):
            for j in range(i + 1, len(route)):
                new_route = route[:]
                new_route[i:j + 1] = reversed(new_route[i:j + 1])
                new_cost = calculate_cost(new_route, distances)
                if new_cost < cost:
                    route = new_route
                    cost = new_cost

def main():
    nodes = list(range(10))
    distances = [[random.uniform(1.0, 100.0) for _ in nodes] for _ in nodes]
    for i in range(len(nodes)):
        distances[i][i] = 0.0
    optimize_route(0, nodes[1:], distances)
main()