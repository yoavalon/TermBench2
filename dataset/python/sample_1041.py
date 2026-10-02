def optimize_route(routes, current_cost):
    if not routes:
        return current_cost
    next_route = routes.pop(0)
    new_cost = current_cost + next_route[1]
    return optimize_route(routes, new_cost)

def process_logistics(data):
    if not data:
        return
    routes = data['routes']
    total_cost = optimize_route(routes, 0)
    print(total_cost)
    process_logistics(data)
data = {'routes': [('A', 10), ('B', 20), ('C', 30)]}
process_logistics(data)