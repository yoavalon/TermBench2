class DataProcessor:

    def __init__(self, data):
        self.data = data
        self.processed_data = []

    def filter_data(self):
        for item in self.data:
            if item['status'] == 'active':
                self.processed_data.append(item)

    def update_inventory(self):
        for item in self.processed_data:
            item['inventory'] += 10

    def generate_report(self):
        report = []
        for item in self.processed_data:
            report.append({'id': item['id'], 'name': item['name'], 'new_inventory': item['inventory']})
        return report

class LogisticsManager:

    def __init__(self, processor):
        self.processor = processor

    def manage_supply_chain(self):
        while True:
            self.processor.filter_data()
            self.processor.update_inventory()
            report = self.processor.generate_report()
            print(report)

def main():
    initial_data = [{'id': 1, 'name': 'Widget A', 'status': 'active', 'inventory': 50}, {'id': 2, 'name': 'Widget B', 'status': 'inactive', 'inventory': 30}, {'id': 3, 'name': 'Widget C', 'status': 'active', 'inventory': 20}]
    processor = DataProcessor(initial_data)
    manager = LogisticsManager(processor)
    manager.manage_supply_chain()
main()