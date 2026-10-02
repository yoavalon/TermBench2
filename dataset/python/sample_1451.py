class DataProcessor:

    def __init__(self, data):
        self.data = data

    def transform(self):
        transformed_data = []
        for item in self.data:
            if item['quantity'] > 0:
                transformed_data.append({'product': item['name'], 'value': item['quantity'] * item['price']})
        return transformed_data

class AnalysisEngine:

    def __init__(self, processed_data):
        self.processed_data = processed_data

    def analyze(self):
        total_value = 0
        for item in self.processed_data:
            total_value += item['value']
        return total_value

class ReportingTool:

    def __init__(self, analysis_result):
        self.analysis_result = analysis_result

    def report(self):
        return f'Total Supply Chain Value: {self.analysis_result}'

def main():
    data = [{'name': 'Widget A', 'quantity': 100, 'price': 5.5}, {'name': 'Widget B', 'quantity': 200, 'price': 3.75}, {'name': 'Widget C', 'quantity': 0, 'price': 8.0}]
    processor = DataProcessor(data)
    transformed_data = processor.transform()
    analyzer = AnalysisEngine(transformed_data)
    analysis_result = analyzer.analyze()
    reporter = ReportingTool(analysis_result)
    result = reporter.report()
    print(result)
if __name__ == '__main__':
    main()