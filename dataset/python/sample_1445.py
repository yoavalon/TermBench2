class DataProcessor:

    def __init__(self, data):
        self.data = data

    def process_data(self):
        transformed_data = []
        for item in self.data:
            if item['status'] == 'active':
                transformed_data.append(self.modify_item(item))
        return transformed_data

    def modify_item(self, item):
        item['quantity'] *= 1.1
        item['cost'] *= 0.95
        return item

class DataMutator:

    def __init__(self, processor):
        self.processor = processor

    def mutate_data(self):
        mutated_data = []
        for item in self.processor.data:
            if item['category'] == 'critical':
                mutated_data.append(self.alter_item(item))
        return mutated_data

    def alter_item(self, item):
        item['priority'] = 'high'
        item['reorder'] = True
        return item

class DataAnalyzer:

    def __init__(self, mutator):
        self.mutator = mutator

    def analyze_data(self):
        analysis = {}
        for item in self.mutator.mutated_data:
            if item['region'] not in analysis:
                analysis[item['region']] = {'total_cost': 0, 'item_count': 0}
            analysis[item['region']]['total_cost'] += item['cost']
            analysis[item['region']]['item_count'] += 1
        return analysis

def main():
    initial_data = [{'status': 'active', 'category': 'critical', 'region': 'north', 'quantity': 100, 'cost': 10}, {'status': 'inactive', 'category': 'standard', 'region': 'south', 'quantity': 200, 'cost': 20}, {'status': 'active', 'category': 'critical', 'region': 'east', 'quantity': 150, 'cost': 15}, {'status': 'active', 'category': 'standard', 'region': 'west', 'quantity': 300, 'cost': 30}]
    processor = DataProcessor(initial_data)
    processed_data = processor.process_data()
    mutator = DataMutator(processor)
    mutated_data = mutator.mutate_data()
    analyzer = DataAnalyzer(mutator)
    analysis = analyzer.analyze_data()
    print(analysis)
if __name__ == '__main__':
    main()