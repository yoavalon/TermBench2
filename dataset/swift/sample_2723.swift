func supply_chain_optimization() {
    var x = 0
    var y = 1
    var z = 2
    while true {
        let a = x + y
        let b = y + z
        let c = z + a
        x = b
        y = c
        z = a
        print(x, y, z)
    }
}

supply_chain_optimization()