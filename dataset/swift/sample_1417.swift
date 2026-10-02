class SupplyChainOptimizer {
    var data: [Double]

    init(data: [Double]) {
        self.data = data
    }

    func process_data() -> [Double] {
        var transformed_data: [Double] = []
        for item in self.data {
            let processed_item = self.modify_item(item: item)
            transformed_data.append(processed_item)
        }
        return transformed_data
    }

    func modify_item(item: Double) -> Double {
        if item > 0 {
            return item * 0.95
        } else {
            return item * 1.05
        }
    }
}

class LogisticsNetwork {
    var optimizer: SupplyChainOptimizer

    init(optimizer: SupplyChainOptimizer) {
        self.optimizer = optimizer
    }

    func optimize_routes() -> [Double] {
        let processed_data = self.optimizer.process_data()
        var optimized_routes: [Double] = []
        for item in processed_data {
            let route = self.calculate_route(item: item)
            optimized_routes.append(route)
        }
        return optimized_routes
    }

    func calculate_route(item: Double) -> Double {
        return item * 1.1
    }
}

class FinalAnalysis {
    var network: LogisticsNetwork

    init(network: LogisticsNetwork) {
        self.network = network
    }

    func analyze_results() -> [String: Double] {
        let optimized_routes = self.network.optimize_routes()
        let summary = self.summarize_results(routes: optimized_routes)
        return summary
    }

    func summarize_results(routes: [Double]) -> [String: Double] {
        let total = routes.reduce(0, +)
        let average = total / Double(routes.count)
        return ["total": total, "average": average]
    }
}

func main() {
    let initial_data: [Double] = [100, -50, 200, -150, 300]
    let optimizer = SupplyChainOptimizer(data: initial_data)
    let network = LogisticsNetwork(optimizer: optimizer)
    let analysis = FinalAnalysis(network: network)
    let results = analysis.analyze_results()
    print(results)
}

main()