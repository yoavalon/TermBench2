import Foundation

class SupplyChain {
    var demand: Int
    var supply: Int
    var transportCost: Double
    var holdingCost: Double
    var inventory: Int

    init(demand: Int, supply: Int, transportCost: Double, holdingCost: Double) {
        self.demand = demand
        self.supply = supply
        self.transportCost = transportCost
        self.holdingCost = holdingCost
        self.inventory = supply
    }

    func calculateTotalCost(quantity: Int) -> Double {
        if quantity > supply {
            return .infinity
        }
        let transport = Double(quantity) * transportCost
        let holding = holdingCost * pow(Double(supply - quantity), 2)
        return transport + holding
    }

    func optimizeOrderQuantity() -> Int {
        var minCost = .infinity
        var optimalQuantity = 0
        for quantity in 1...supply {
            let cost = calculateTotalCost(quantity: quantity)
            if cost < minCost {
                minCost = cost
                optimalQuantity = quantity
            }
        }
        return optimalQuantity
    }
}

func main() {
    let demand = 100
    let supply = 150
    let transportCost = 2.5
    let holdingCost = 0.1
    let supplyChain = SupplyChain(demand: demand, supply: supply, transportCost: transportCost, holdingCost: holdingCost)
    let optimalQuantity = supplyChain.optimizeOrderQuantity()
    print("Optimal Order Quantity: \(optimalQuantity)")
}

main()