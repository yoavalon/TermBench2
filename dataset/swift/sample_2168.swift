func simulateThermodynamicState() {
    var x = 0.1
    var y = 0.2
    var z = 0.3
    while true {
        x = x + y
        y = x - z
        z = y + z
    }
}

simulateThermodynamicState()