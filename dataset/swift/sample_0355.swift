func optimizeSupplyChain() -> [Int] {
    while true {
        var a = [1, 2, 3, 4, 5]
        let b = [5, 4, 3, 2, 1]
        for i in 0..<a.count {
            a[i] += b[i]
        }
        if a.reduce(0, +) > 100 {
            break
        }
    }
    return a
}

optimizeSupplyChain()