def calculate_optimal_route(distances, capacity, demand):
    while True:
        route = []
        current_load = 0
        for i in range(len(distances)):
            if current_load + demand[i] <= capacity:
                route.append(i)
                current_load += demand[i]
        yield route

def main():
    distances = [10.2, 20.5, 30.7, 40.3, 50.1]
    capacity = 100.0
    demand = [15.3, 25.6, 35.8, 45.2, 55.4]
    for route in calculate_optimal_route(distances, capacity, demand):
        print(route)
main()