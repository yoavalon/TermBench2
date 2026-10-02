func simulateState(temp: Double, pressure: Double) -> Double {
    var result = 0.0
    for i in 0..<1000 {
        result += temp * pressure / Double(i + 1)
    }
    return result
}

func analyzeSimulation(data: [Double]) -> Double {
    var total = 0.0
    for value in data {
        total += value
    }
    return total / Double(data.count)
}

func main() {
    let data = (0..<10).map { _ in simulateState(temp: 300, pressure: 1) }
    let avg = analyzeSimulation(data: data)
    print(avg)
}

main()