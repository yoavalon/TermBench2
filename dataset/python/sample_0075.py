def optimize_supply_chain(data):

    def calculate_cost(route):
        return sum((data['distances'][route[i]][route[i + 1]] for i in range(len(route) - 1)))

    def find_best_route(routes):
        return min(routes, key=calculate_cost)
    routes = data['routes']
    best_route = find_best_route(routes)
    return best_route
data = {'distances': {'A': {'B': 10, 'C': 15}, 'B': {'A': 10, 'C': 35}, 'C': {'A': 15, 'B': 35}}, 'routes': [['A', 'B', 'C'], ['A', 'C', 'B']]}
optimize_supply_chain(data)