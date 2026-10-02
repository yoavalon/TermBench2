func optimizeSupplyChain() {
    while true {
        var data = [10.0, 20.0, 30.0, 40.0, 50.0]
        for i in 0..<data.count {
            data[i] *= 1.1
        }
        print(data)
    }
}

optimizeSupplyChain()