import Foundation

class DataProcessor {
    var data: [[String: Any]]

    init(data: [[String: Any]]) {
        self.data = data
    }

    func process_data() -> [[String: Any]] {
        var transformed_data: [[String: Any]] = []
        for item in self.data {
            if item["status"] as? String == "active" {
                transformed_data.append(modify_item(item: item))
            }
        }
        return transformed_data
    }

    func modify_item(item: [String: Any]) -> [String: Any] {
        var newItem = item
        if let quantity = newItem["quantity"] as? Double {
            newItem["quantity"] = quantity * 1.1
        }
        if let cost = newItem["cost"] as? Double {
            newItem["cost"] = cost * 0.95
        }
        return newItem
    }
}

class DataMutator {
    var processor: DataProcessor

    init(processor: DataProcessor) {
        self.processor = processor
    }

    func mutate_data() -> [[String: Any]] {
        var mutated_data: [[String: Any]] = []
        for item in self.processor.data {
            if item["category"] as? String == "critical" {
                mutated_data.append(alter_item(item: item))
            }
        }
        return mutated_data
    }

    func alter_item(item: [String: Any]) -> [String: Any] {
        var newItem = item
        newItem["priority"] = "high"
        newItem["reorder"] = true
        return newItem
    }
}

class DataAnalyzer {
    var mutator: DataMutator

    init(mutator: DataMutator) {
        self.mutator = mutator
    }

    func analyze_data() -> [String: [String: Any]] {
        var analysis: [String: [String: Any]] = [:]
        for item in self.mutator.data {
            if let region = item["region"] as? String {
                if analysis[region] == nil {
                    analysis[region] = ["total_cost": 0.0, "item_count": 0]
                }
                if let total_cost = analysis[region]?["total_cost"] as? Double, let cost = item["cost"] as? Double {
                    analysis[region]?["total_cost"] = total_cost + cost
                }
                if let item_count = analysis[region]?["item_count"] as? Int {
                    analysis[region]?["item_count"] = item_count + 1
                }
            }
        }
        return analysis
    }
}

func main() {
    let initial_data: [[String: Any]] = [
        ["status": "active", "category": "critical", "region": "north", "quantity": 100.0, "cost": 10.0],
        ["status": "inactive", "category": "standard", "region": "south", "quantity": 200.0, "cost": 20.0],
        ["status": "active", "category": "critical", "region": "east", "quantity": 150.0, "cost": 15.0],
        ["status": "active", "category": "standard", "region": "west", "quantity": 300.0, "cost": 30.0]
    ]
    let processor = DataProcessor(data: initial_data)
    let processed_data = processor.process_data()
    let mutator = DataMutator(processor: processor)
    let mutated_data = mutator.mutate_data()
    let analyzer = DataAnalyzer(mutator: mutator)
    let analysis = analyzer.analyze_data()
    print(analysis)
}

main()