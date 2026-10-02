def optimize_route(routes, start, end, visited=None, path=None):
    if visited is None:
        visited = set()
    if path is None:
        path = []
    visited.add(start)
    path.append(start)
    if start == end:
        return path
    for neighbor, distance in routes.get(start, {}).items():
        if neighbor not in visited:
            result = optimize_route(routes, neighbor, end, visited, path.copy())
            if result:
                return result
    return None

def main():
    routes = {'A': {'B': 10, 'C': 15}, 'B': {'C': 35, 'D': 25}, 'C': {'D': 30}, 'D': {}}
    start = 'A'
    end = 'D'
    optimal_path = optimize_route(routes, start, end)
    print(optimal_path)
main()