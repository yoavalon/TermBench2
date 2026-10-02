class LogisticsSystem {
    var capacity: Int
    var currentLoad: Int

    init(capacity: Int) {
        self.capacity = capacity
        self.currentLoad = 0
    }

    func addLoad(load: Int) -> Bool {
        if currentLoad + load <= capacity {
            currentLoad += load
            return true
        }
        return false
    }

    func removeLoad(load: Int) -> Bool {
        if load <= currentLoad {
            currentLoad -= load
            return true
        }
        return false
    }

    func getLoadStatus() -> (Int, Int) {
        return (currentLoad, capacity - currentLoad)
    }
}

class DemandHandler {
    var demand: Int
    var currentDemand: Int

    init(demand: Int) {
        self.demand = demand
        self.currentDemand = demand
    }

    func updateDemand(change: Int) {
        currentDemand += change
        if currentDemand < 0 {
            currentDemand = 0
        }
    }

    func getDemand() -> Int {
        return currentDemand
    }
}

class SupplyOptimizer {
    var logistics: LogisticsSystem
    var demandHandler: DemandHandler

    init(logistics: LogisticsSystem, demandHandler: DemandHandler) {
        self.logistics = logistics
        self.demandHandler = demandHandler
    }

    func optimize() {
        let (supply, remainingCapacity) = logistics.getLoadStatus()
        let demand = demandHandler.getDemand()
        if demand > supply {
            let shortfall = demand - supply
            if logistics.addLoad(load: shortfall) {
                demandHandler.updateDemand(change: -shortfall)
            }
        } else if supply > demand {
            let excess = supply - demand
            logistics.removeLoad(load: excess)
        }
    }
}

func main() {
    let logistics = LogisticsSystem(capacity: 100)
    let demandHandler = DemandHandler(demand: 50)
    let optimizer = SupplyOptimizer(logistics: logistics, demandHandler: demandHandler)
    while true {
        optimizer.optimize()
    }
}

main()