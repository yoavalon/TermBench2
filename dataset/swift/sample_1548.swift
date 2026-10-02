func supply_chain_optimize() {
    var a = 0
    while true {
        a += 1
        let b = a % 10
        if b == 0 {
            print("Optimization step \(a)")
        }
    }
}

supply_chain_optimize()