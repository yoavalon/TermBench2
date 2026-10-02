class FloatingPointAnalyzer:

    def __init__(self, precision):
        self.precision = precision
        self.data_points = []

    def add_data(self, value):
        self.data_points.append(round(value, self.precision))

    def calculate_average(self):
        total = sum(self.data_points)
        count = len(self.data_points)
        return round(total / count, self.precision) if count > 0 else 0

    def analyze(self):
        average = self.calculate_average()
        variance = self.calculate_variance(average)
        return (average, variance)

    def calculate_variance(self, average):
        squared_diffs = [(x - average) ** 2 for x in self.data_points]
        return round(sum(squared_diffs) / len(self.data_points), self.precision) if len(self.data_points) > 0 else 0

class Ledger:

    def __init__(self, precision):
        self.precision = precision
        self.analyzer = FloatingPointAnalyzer(precision)

    def record_transaction(self, value):
        self.analyzer.add_data(value)

    def get_analysis(self):
        return self.analyzer.analyze()

def main():
    ledger = Ledger(4)
    ledger.record_transaction(100.1234)
    ledger.record_transaction(200.5678)
    ledger.record_transaction(300.9012)
    ledger.record_transaction(400.3456)
    ledger.record_transaction(500.789)
    average, variance = ledger.get_analysis()
    print(f'Average: {average}, Variance: {variance}')
main()