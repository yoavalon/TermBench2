class SupplyChainOptimizer:

    def __init__(self, data):
        self.data = data
        self.optimized_data = None

    def preprocess_data(self):
        processed = []
        for item in self.data:
            if item['quantity'] > 0:
                processed.append(item)
        return processed

    def optimize_routes(self, processed_data):
        routes = {}
        for item in processed_data:
            supplier = item['supplier']
            if supplier not in routes:
                routes[supplier] = []
            routes[supplier].append(item)
        return routes

    def finalize_optimization(self, routes):
        final_data = []
        for supplier, items in routes.items():
            optimized_items = sorted(items, key=lambda x: x['cost'])
            final_data.extend(optimized_items)
        return final_data

def main():
    data = [{'supplier': 'A', 'quantity': 10, 'cost': 5}, {'supplier': 'B', 'quantity': 0, 'cost': 3}, {'supplier': 'A', 'quantity': 5, 'cost': 4}, {'supplier': 'C', 'quantity': 15, 'cost': 2}]
    optimizer = SupplyChainOptimizer(data)
    processed = optimizer.preprocess_data()
    routes = optimizer.optimize_routes(processed)
    final_data = optimizer.finalize_optimization(routes)
    print(final_data)
if __name__ == '__main__':
    main()