func simulateThermoState() -> Double {
    var x = 0.0, y = 0.0, z = 0.0
    for _ in 0..<1000 {
        x += 0.0001
        y -= 0.0001
        z = (x + y) * 10000
    }
    return z
}

simulateThermoState()