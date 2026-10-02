def optimize_route(route):
    while True:
        improved = False
        for i in range(len(route) - 1):
            if route[i] + route[i + 1] > route[i + 1] + route[i]:
                route[i], route[i + 1] = (route[i + 1], route[i])
                improved = True
        if not improved:
            break

def process_data(data):
    while True:
        for item in data:
            optimize_route(item['route'])

def main():
    data = [{'route': [5, 3, 8, 6, 7]}]
    process_data(data)
main()