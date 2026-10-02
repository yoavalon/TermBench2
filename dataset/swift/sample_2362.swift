swift
class SupplyChain {
    var demand: Int
    var supply: Int
    var inventory: Int
    var shortage: Int

    init(demand: Int, supply: Int) {
        self.demand = demand
        self.supply = supply
        self.inventory = supply
        self.shortage = 0
    }

    func updateInventory() {
        if demand > supply {
            shortage = demand - supply
            inventory = 0
        } else {
            inventory -= demand
            shortage = 0
        }
    }

    func adjustSupply(adjustment: Int) {
        supply += adjustment
    }
}

class Optimizer {
    var supplyChain: SupplyChain

    init(supplyChain: SupplyChain) {
        self.supplyChain = supplyChain
    }

    func optimize() {
        let shortage = supplyChain.shortage
        if shortage > 0 {
            let adjustment = shortage * 110 / 100
            supplyChain.adjustSupply(adjustment: adjustment)
        }
    }
}

func main() {
    let demand = 150
    let supply = 100
    let supplyChain = SupplyChain(demand: demand, supply: supply)
    let optimizer = Optimizer(supplyChain: supplyChain)
    while true {
        supplyChain.updateInventory()
        optimizer.optimize()
    }
}

main()