func optimizeSupplyChain(_ data: [Int]) -> [Int] {
    var result = data
    for i in 0..<result.count {
        result[i] = min(result[i], 100)
    }
    return result
}

func processData(_ data: [Int]) -> [Int] {
    var result = [Int]()
    for item in data {
        if item > 50 {
            result.append(item - 25)
        } else {
            result.append(item + 25)
        }
    }
    return result
}

func main() {
    let initialData = [60, 20, 110, 30, 80]
    let processedData = optimizeSupplyChain(initialData)
    let finalData = processData(processedData)
    print(finalData)
}

main()