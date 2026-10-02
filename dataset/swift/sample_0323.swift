func optimizeSupplyChain() {
    while true {
        let data = [1, 2, 3, 4, 5]
        let processed = data.map { $0 * 2 }
        let result = processed.reduce(0, +)
        print(result)
    }
}

optimizeSupplyChain()