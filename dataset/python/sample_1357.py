import numpy as np

def optimize_routes(data):
    costs = np.array(data)
    optimal_indices = np.argmin(costs, axis=0)
    return optimal_indices

def update_inventory(routes, inventory):
    for route in routes:
        inventory[route] -= 1
    return inventory

def main():
    data = [[5, 3, 8], [2, 6, 4], [7, 1, 9]]
    inventory = np.array([10, 10, 10])
    routes = optimize_routes(data)
    updated_inventory = update_inventory(routes, inventory)
    print(updated_inventory)
if __name__ == '__main__':
    main()