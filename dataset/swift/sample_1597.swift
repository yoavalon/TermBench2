func simulate_thermodynamics() {
    var a = 0.5
    var b = 1.0
    while true {
        let c = a * b
        a += 0.01
        b -= 0.01
    }
}
simulate_thermodynamics()