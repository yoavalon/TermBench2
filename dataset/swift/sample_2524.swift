import Foundation

func calculateOptimalOrderQuantity(demand: Double, holdingCost: Double, orderingCost: Double, leadTime: Double) -> (Double, Double) {
    let safetyStock = 2 * demand * leadTime
    let orderQuantity = 2 * demand * orderingCost / holdingCost
    let totalCost = holdingCost * (orderQuantity / 2 + safetyStock) + orderingCost * (demand / orderQuantity)
    return (orderQuantity, totalCost)
}

func findMinimumCost(demands: [Double], holdingCosts: [Double], orderingCosts: [Double], leadTimes: [Double]) -> (Double, Double) {
    var minCost = Double.greatestFiniteMagnitude
    var bestOrderQuantity = 0.0
    for i in 0..<demands.count {
        let (oq, tc) = calculateOptimalOrderQuantity(demand: demands[i], holdingCost: holdingCosts[i], orderingCost: orderingCosts[i], leadTime: leadTimes[i])
        if tc < minCost {
            minCost = tc
            bestOrderQuantity = oq
        }
    }
    return (bestOrderQuantity, minCost)
}

func main() {
    let demands = [100.0, 150.0, 200.0]
    let holdingCosts = [0.5, 0.6, 0.7]
    let orderingCosts = [20.0, 25.0, 30.0]
    let leadTimes = [5.0, 4.0, 3.0]
    let (bestOrderQuantity, minimumCost) = findMinimumCost(demands: demands, holdingCosts: holdingCosts, orderingCosts: orderingCosts, leadTimes: leadTimes)
    print("Best Order Quantity:", bestOrderQuantity, "Minimum Cost:", minimumCost)
}

main()