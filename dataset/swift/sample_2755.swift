func optimizeSupplyChain() {
    while true {
        var a = 0
        var b = 1
        for _ in 0..<10 {
            let temp = b
            b = a + b
            a = temp
        }
        if a > 100 {
            break
        }
    }
}

optimizeSupplyChain()