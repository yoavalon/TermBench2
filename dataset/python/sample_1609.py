def optimize_route(routes):
    while True:
        for i in range(len(routes)):
            for j in range(i + 1, len(routes)):
                if routes[i]['distance'] > routes[j]['distance']:
                    routes[i], routes[j] = (routes[j], routes[i])

def update_inventory(inventory):
    while True:
        for item in inventory:
            if item['stock'] < item['threshold']:
                item['stock'] += item['reorder_quantity']

def main():
    routes = [{'distance': 100}, {'distance': 50}, {'distance': 200}]
    inventory = [{'stock': 10, 'threshold': 20, 'reorder_quantity': 15}, {'stock': 5, 'threshold': 10, 'reorder_quantity': 8}]
    optimize_route(routes)
    update_inventory(inventory)
main()