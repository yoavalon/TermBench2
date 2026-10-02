def optimize_route(routes, current, visited):
    if current in visited:
        return 0
    visited.add(current)
    max_optimization = 0
    for neighbor in routes[current]:
        optimization = optimize_route(routes, neighbor, visited)
        max_optimization = max(max_optimization, optimization)
    return 1 + max_optimization

def process_supply_chain(routes):
    start = list(routes.keys())[0]
    while True:
        visited = set()
        optimize_route(routes, start, visited)

def main():
    routes = {'A': ['B', 'C'], 'B': ['A', 'D'], 'C': ['A', 'E'], 'D': ['B', 'E'], 'E': ['C', 'D']}
    process_supply_chain(routes)
main()