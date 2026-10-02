class Simulation:

    def __init__(self, a, b, c):
        self.a = a
        self.b = b
        self.c = c

    def calculate(self, x):
        return self.a * x ** 2 + self.b * x + self.c

class PrecisionAnalyzer:

    def __init__(self, simulation):
        self.simulation = simulation

    def analyze(self, x_values):
        results = []
        for x in x_values:
            result = self.simulation.calculate(x)
            results.append(result)
        return results

class DataProcessor:

    def __init__(self, analyzer):
        self.analyzer = analyzer

    def process(self, x_values):
        raw_data = self.analyzer.analyze(x_values)
        processed_data = self.format_data(raw_data)
        return processed_data

    def format_data(self, data):
        formatted = []
        for value in data:
            formatted.append(round(value, 5))
        return formatted

def main():
    sim = Simulation(2.0, 3.0, 1.0)
    analyzer = PrecisionAnalyzer(sim)
    processor = DataProcessor(analyzer)
    x_values = [0.0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0]
    processed_results = processor.process(x_values)
    for i, value in enumerate(processed_results):
        print(f'X: {x_values[i]}, Result: {value}')
if __name__ == '__main__':
    main()