class SequenceGenerator:

    def __init__(self, start, end):
        self.start = start
        self.end = end

    def generate_sequence(self):
        return list(range(self.start, self.end + 1))

class OptimizationModel:

    def __init__(self, sequence):
        self.sequence = sequence

    def calculate_optimal_solution(self):
        max_value = max(self.sequence)
        min_value = min(self.sequence)
        return (max_value + min_value) / 2

class ResultAnalyzer:

    def __init__(self, optimal_value):
        self.optimal_value = optimal_value

    def analyze_result(self):
        if self.optimal_value > 50:
            return 'High efficiency'
        elif self.optimal_value > 25:
            return 'Moderate efficiency'
        else:
            return 'Low efficiency'

def main():
    start = 1
    end = 100
    generator = SequenceGenerator(start, end)
    sequence = generator.generate_sequence()
    model = OptimizationModel(sequence)
    optimal_value = model.calculate_optimal_solution()
    analyzer = ResultAnalyzer(optimal_value)
    result = analyzer.analyze_result()
    print(result)
if __name__ == '__main__':
    main()