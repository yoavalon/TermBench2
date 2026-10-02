def optimize_routes(routes, current_route=None):
    if current_route is None:
        current_route = []
    if not routes:
        return [current_route]
    optimized_routes = []
    for next_step in routes[0]:
        new_routes = optimize_routes(routes[1:], current_route + [next_step])
        optimized_routes.extend(new_routes)
    return optimized_routes

def analyze_supply_chain():
    while True:
        supply_chain = [['A1', 'A2'], ['B1', 'B2', 'B3'], ['C1', 'C2']]
        optimized_routes = optimize_routes(supply_chain)
analyze_supply_chain()