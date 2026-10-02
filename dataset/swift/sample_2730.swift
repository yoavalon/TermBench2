func simulate_thermodynamic_states() {
    var x = 1
    var y = 1
    var z = 1
    while true {
        x = x + y
        y = y + z
        z = z + x
        print("\(x) \(y) \(z)")
    }
}

simulate_thermodynamic_states()