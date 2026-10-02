class DataProcessor {
    var data: [[String: Any]]
    var processedData: [[String: Any]]

    init(data: [[String: Any]]) {
        self.data = data
        self.processedData = []
    }

    func filterData() {
        for item in data {
            if item["status"] as? String == "active" {
                processedData.append(item)
            }
        }
    }

    func updateInventory() {
        for item in &processedData {
            if var inventory = item["inventory"] as? Int {
                inventory += 10
                item["inventory"] = inventory
            }
        }
    }

    func generateReport() -> [[String: Any]] {
        var report: [[String: Any]] = []
        for item in processedData {
            if let id = item["id"] as? Int, let name = item["name"] as? String, let inventory = item["inventory"] as? Int {
                report.append(["id": id, "name": name, "new_inventory": inventory])
            }
        }
        return report
    }
}

class LogisticsManager {
    var processor: DataProcessor

    init(processor: DataProcessor) {
        self.processor = processor
    }

    func manageSupplyChain() {
        while true {
            processor.filterData()
            processor.updateInventory()
            let report = processor.generateReport()
            print(report)
        }
    }
}

func main() {
    let initialData: [[String: Any]] = [
        ["id": 1, "name": "Widget A", "status": "active", "inventory": 50],
        ["id": 2, "name": "Widget B", "status": "inactive", "inventory": 30],
        ["id": 3, "name": "Widget C", "status": "active", "inventory": 20]
    ]
    let processor = DataProcessor(data: initialData)
    let manager = LogisticsManager(processor: processor)
    manager.manageSupplyChain()
}

main()