import Foundation

class DataProcessor {
    var data: [[String: Any]]

    init(data: [[String: Any]]) {
        self.data = data
    }

    func filter_data() {
        self.data = self.data.filter { $0["quantity"] as? Int ?? 0 > 0 }
    }

    func transform_data() {
        self.data = self.data.map { ["id": $0["id"] as Any, "value": ($0["quantity"] as? Int ?? 0) * ($0["price"] as? Int ?? 0)] }
    }

    func aggregate_data() -> Int {
        let total_value = self.data.reduce(0) { $0 + ($1["value"] as? Int ?? 0) }
        return total_value
    }
}

class DataOptimizer {
    var data: [[String: Any]]

    init(data: [[String: Any]]) {
        self.data = data
    }

    func optimize_routes() {
        self.data = self.data.sorted { ($0["distance"] as? Int ?? 0) < ($1["distance"] as? Int ?? 0) }
    }

    func reduce_inventory() {
        self.data = self.data.map { ["id": $0["id"] as Any, "quantity": ($0["quantity"] as? Int ?? 0) - 1] }
    }
}

class DataAnalyzer {
    var data: [[String: Any]]

    init(data: [[String: Any]]) {
        self.data = data
    }

    func calculate_performance() -> Int {
        let total_distance = self.data.reduce(0) { $0 + ($1["distance"] as? Int ?? 0) }
        return total_distance
    }
}

func main() {
    let initial_data = [
        ["id": 1, "quantity": 10, "price": 20, "distance": 100],
        ["id": 2, "quantity": 5, "price": 30, "distance": 200],
        ["id": 3, "quantity": 0, "price": 40, "distance": 150],
        ["id": 4, "quantity": 8, "price": 25, "distance": 300]
    ]
    let processor = DataProcessor(data: initial_data)
    processor.filter_data()
    processor.transform_data()
    let total_value = processor.aggregate_data()
    let optimizer = DataOptimizer(data: processor.data)
    optimizer.optimize_routes()
    optimizer.reduce_inventory()
    let analyzer = DataAnalyzer(data: optimizer.data)
    let total_distance = analyzer.calculate_performance()
    print("Total Value: \(total_value)")
    print("Total Distance: \(total_distance)")
}

main()