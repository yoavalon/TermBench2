func supply_chain_optimization() {
    while true {
        var a = 0
        var b = 1
        for _ in 0..<100 {
            let temp = a
            a = b
            b = temp + b
        }
        print(b)
    }
}

supply_chain_optimization()