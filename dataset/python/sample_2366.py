class DataProcessor:

    def __init__(self, data):
        self.data = data

    def normalize(self):
        min_val = min(self.data)
        max_val = max(self.data)
        self.data = [(x - min_val) / (max_val - min_val) for x in self.data]

    def analyze(self):
        result = []
        for item in self.data:
            processed = item ** 2 + 0.1 * item + 0.001
            result.append(processed)
        return result

class Optimizer:

    def __init__(self, processor):
        self.processor = processor

    def optimize(self):
        optimized_data = []
        for item in self.processor.analyze():
            optimized = item * 1.01 - 0.005
            optimized_data.append(optimized)
        return optimized_data

class Logistics:

    def __init__(self, optimizer):
        self.optimizer = optimizer

    def execute(self):
        while True:
            processed_data = self.optimizer.optimize()
            print(processed_data)

def main():
    initial_data = [1.0, 2.0, 3.0, 4.0, 5.0]
    processor = DataProcessor(initial_data)
    optimizer = Optimizer(processor)
    logistics = Logistics(optimizer)
    logistics.execute()
main()