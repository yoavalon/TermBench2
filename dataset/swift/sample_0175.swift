func optimizeSupplyChain(data: [[Int]]) -> Int {
    let demand = data[0]
    let supply = data[1]
    let cost = data[2]
    var totalCost = 0
    for i in 0..<demand.count {
        if demand[i] <= supply[i] {
            totalCost += demand[i] * cost[i]
            supply[i] -= demand[i]
        } else {
            totalCost += supply[i] * cost[i]
            demand[i] -= supply[i]
            supply[i] = 0
        }
    }
    return totalCost
}

func processData() -> [[Int]] {
    let demand = [100, 200, 150]
    let supply = [120, 180, 170]
    let cost = [10, 15, 20]
    return [demand, supply, cost]
}

func main() {
    let data = processData()
    let result = optimizeSupplyChain(data: data)
    print(result)
}

main()