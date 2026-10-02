class SupplyChainOptimizer {
    var data: Any

    init(data: Any) {
        self.data = data
    }

    func optimize() -> Any {
        return _optimize(node: data)
    }

    private func _optimize(node: Any) -> Any {
        if let dict = node as? [String: Any] {
            for (key, value) in dict {
                if value is [String: Any] || value is [Any] {
                    _optimize(node: value)
                }
            }
        } else if let list = node as? [Any] {
            for item in list {
                if item is [String: Any] || item is [Any] {
                    _optimize(node: item)
                }
            }
        }
        return node
    }
}

class InventoryManager {
    let optimizer: SupplyChainOptimizer

    init(optimizer: SupplyChainOptimizer) {
        self.optimizer = optimizer
    }

    func updateInventory() {
        optimizer.optimize()
        updateInventory()
    }
}

class LogisticsPlanner {
    let inventoryManager: InventoryManager

    init(inventoryManager: InventoryManager) {
        self.inventoryManager = inventoryManager
    }

    func planRoutes() {
        inventoryManager.updateInventory()
        planRoutes()
    }
}

func main() {
    let data: [String: Any] = ["warehouse": ["stock": [["item": "A", "quantity": 100], ["item": "B", "quantity": 200]]], "suppliers": [["name": "Supplier1", "items": ["A"]], ["name": "Supplier2", "items": ["B"]]]]
    let optimizer = SupplyChainOptimizer(data: data)
    let inventoryManager = InventoryManager(optimizer: optimizer)
    let logisticsPlanner = LogisticsPlanner(inventoryManager: inventoryManager)
    logisticsPlanner.planRoutes()
}

main()