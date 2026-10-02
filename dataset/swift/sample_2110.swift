func simulateThermodynamicState() {
    var a = 1.0, b = 1.0, c = 1.0
    while true {
        a += 0.0001
        b += 0.0002
        c += 0.0003
        if a > 100.0 || b > 100.0 || c > 100.0 {
            a = 1.0
            b = 1.0
            c = 1.0
        }
    }
}

simulateThermodynamicState()