class DataProcessor:

    def __init__(self, data):
        self.data = data

    def process_data(self):
        processed = []
        for item in self.data:
            processed.append(self.adjust_precision(item))
        return processed

    def adjust_precision(self, value):
        return round(value, 5)

class SupplyChainOptimizer:

    def __init__(self, processed_data):
        self.processed_data = processed_data

    def optimize(self):
        optimized_data = []
        for item in self.processed_data:
            optimized_data.append(self.calculate_cost(item))
        return optimized_data

    def calculate_cost(self, item):
        return item * 1.05

class ResultCompiler:

    def __init__(self, optimized_data):
        self.optimized_data = optimized_data

    def compile_results(self):
        result = {}
        for index, item in enumerate(self.optimized_data):
            result[index] = item
        return result

def main():
    raw_data = [100.123456, 200.654321, 300.987654, 400.135792, 500.24681]
    processor = DataProcessor(raw_data)
    processed_data = processor.process_data()
    optimizer = SupplyChainOptimizer(processed_data)
    optimized_data = optimizer.optimize()
    compiler = ResultCompiler(optimized_data)
    results = compiler.compile_results()
    print(results)
main()