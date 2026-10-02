func supply_chain_optimize() {
    var data = [10, 20, 30, 40, 50]
    while true {
        for i in 0..<data.count {
            data[i] *= 1.05
        }
        print(data)
    }
}

supply_chain_optimize()