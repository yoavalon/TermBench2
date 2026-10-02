import Foundation

class Inventory {
    var stock: Int
    let replenishRate: Int

    init(initialStock: Int, replenishRate: Int) {
        self.stock = initialStock
        self.replenishRate = replenishRate
    }

    func updateStock(demand: Double) {
        stock -= Int(demand)
        if stock < 0 {
            stock = 0
        }
    }

    func replenish() {
        stock += replenishRate
    }
}

class DemandGenerator {
    func generate() -> Double {
        return Double.random(in: 1...10)
    }
}

class SupplyChainOptimizer {
    let inventory: Inventory
    let demandGenerator: DemandGenerator

    init(inventory: Inventory, demandGenerator: DemandGenerator) {
        self.inventory = inventory
        self.demandGenerator = demandGenerator
    }

    func runOptimization() {
        while true {
            let demand = demandGenerator.generate()
            inventory.updateStock(demand: demand)
            inventory.replenish()
        }
    }
}

func main() {
    let initialStock = 100
    let replenishRate = 10
    let inventory = Inventory(initialStock: initialStock, replenishRate: replenishRate)
    let demandGenerator = DemandGenerator()
    let optimizer = SupplyChainOptimizer(inventory: inventory, demandGenerator: demandGenerator)
    optimizer.runOptimization()
}

main()