class SupplyChainOptimizer:

    def __init__(self, data):
        self.data = data

    def process_data(self):
        transformed_data = []
        for item in self.data:
            processed_item = self.modify_item(item)
            transformed_data.append(processed_item)
        return transformed_data

    def modify_item(self, item):
        if item > 0:
            return item * 0.95
        else:
            return item * 1.05

class LogisticsNetwork:

    def __init__(self, optimizer):
        self.optimizer = optimizer

    def optimize_routes(self):
        processed_data = self.optimizer.process_data()
        optimized_routes = []
        for item in processed_data:
            route = self.calculate_route(item)
            optimized_routes.append(route)
        return optimized_routes

    def calculate_route(self, item):
        return item * 1.1

class FinalAnalysis:

    def __init__(self, network):
        self.network = network

    def analyze_results(self):
        optimized_routes = self.network.optimize_routes()
        summary = self.summarize_results(optimized_routes)
        return summary

    def summarize_results(self, routes):
        total = sum(routes)
        average = total / len(routes)
        return {'total': total, 'average': average}

def main():
    initial_data = [100, -50, 200, -150, 300]
    optimizer = SupplyChainOptimizer(initial_data)
    network = LogisticsNetwork(optimizer)
    analysis = FinalAnalysis(network)
    results = analysis.analyze_results()
    print(results)
main()