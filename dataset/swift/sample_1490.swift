class SupplyChain {
    var inventory: Int
    var demand: Int
    var cost: Int

    init(inventory: Int, demand: Int, cost: Int) {
        self.inventory = inventory
        self.demand = demand
        self.cost = cost
    }

    func updateInventory(supply: Int) {
        self.inventory += supply
    }

    func meetDemand() -> (Int, Int) {
        if self.demand > self.inventory {
            let shortage = self.demand - self.inventory
            return (shortage, 0)
        } else {
            self.inventory -= self.demand
            return (0, self.demand)
        }
    }

    func calculateCost() -> Int {
        return self.demand * self.cost
    }
}

class Optimizer {
    let supplyChain: SupplyChain
    let supply: Int

    init(supplyChain: SupplyChain, supply: Int) {
        self.supplyChain = supplyChain
        self.supply = supply
    }

    func optimize() -> (Int, Int, Int) {
        self.supplyChain.updateInventory(supply: self.supply)
        let (shortage, fulfilled) = self.supplyChain.meetDemand()
        let cost = self.supplyChain.calculateCost()
        return (shortage, fulfilled, cost)
    }
}

func main() {
    let inventory = 100
    let demand = 150
    let cost = 10
    let supply = 60
    let supplyChain = SupplyChain(inventory: inventory, demand: demand, cost: cost)
    let optimizer = Optimizer(supplyChain: supplyChain, supply: supply)
    let (shortage, fulfilled, cost) = optimizer.optimize()
    print("Shortage: \(shortage), Fulfilled: \(fulfilled), Cost: \(cost)")
}

main()