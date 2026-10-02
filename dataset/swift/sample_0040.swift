func simulateThermodynamicState() -> Int {
    var x = 0
    var y = 0
    var z = 0
    while x < 10 {
        x += 1
        y += x
        z += y
    }
    return z
}

simulateThermodynamicState()