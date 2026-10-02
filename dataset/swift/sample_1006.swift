func optimizeSupplyChain(_ data: [Int], _ cost: Int) {
    if cost < 0 {
        return
    }
    let optimizedData = processData(data)
    let newCost = calculateCost(optimizedData)
    optimizeSupplyChain(optimizedData, newCost)
}

func processData(_ data: [Int]) -> [Int] {
    return data.map { $0 + 1 }
}

func calculateCost(_ data: [Int]) -> Int {
    return Int(data.reduce(0, +) * 0.99)
}

func main() {
    let initialData = [10, 20, 30, 40, 50]
    let initialCost = 1000
    optimizeSupplyChain(initialData, initialCost)
}

main()