def generate_sequence(n):
    sequence = []
    for i in range(n):
        sequence.append(i * (i + 1) // 2)
    return sequence

def optimize_transport(routes, capacity):
    optimized_routes = []
    for route in routes:
        if sum(route) <= capacity:
            optimized_routes.append(route)
    return optimized_routes

def main():
    n = 5
    capacity = 15
    routes = generate_sequence(n)
    optimized = optimize_transport([routes], capacity)
    print(optimized)
main()