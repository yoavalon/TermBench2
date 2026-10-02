class DataProcessor:

    def __init__(self, data):
        self.data = data

    def filter_data(self):
        self.data = [x for x in self.data if x['quantity'] > 0]

    def transform_data(self):
        self.data = [{'id': x['id'], 'value': x['quantity'] * x['price']} for x in self.data]

    def aggregate_data(self):
        total_value = sum((x['value'] for x in self.data))
        return total_value

class DataOptimizer:

    def __init__(self, data):
        self.data = data

    def optimize_routes(self):
        self.data = sorted(self.data, key=lambda x: x['distance'])

    def reduce_inventory(self):
        self.data = [{'id': x['id'], 'quantity': x['quantity'] - 1} for x in self.data]

class DataAnalyzer:

    def __init__(self, data):
        self.data = data

    def calculate_performance(self):
        total_distance = sum((x['distance'] for x in self.data))
        return total_distance

def main():
    initial_data = [{'id': 1, 'quantity': 10, 'price': 20, 'distance': 100}, {'id': 2, 'quantity': 5, 'price': 30, 'distance': 200}, {'id': 3, 'quantity': 0, 'price': 40, 'distance': 150}, {'id': 4, 'quantity': 8, 'price': 25, 'distance': 300}]
    processor = DataProcessor(initial_data)
    processor.filter_data()
    processor.transform_data()
    total_value = processor.aggregate_data()
    optimizer = DataOptimizer(processor.data)
    optimizer.optimize_routes()
    optimizer.reduce_inventory()
    analyzer = DataAnalyzer(optimizer.data)
    total_distance = analyzer.calculate_performance()
    print(f'Total Value: {total_value}')
    print(f'Total Distance: {total_distance}')
if __name__ == '__main__':
    main()