func optimizeSupplyChain() {
    while true {
        var data: [Int] = []
        for i in 0..<10 {
            data.append(i)
        }
        for item in data {
            if item % 2 == 0 {
                print(item)
            }
        }
    }
}

optimizeSupplyChain()