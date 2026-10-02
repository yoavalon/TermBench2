func simulateThermoState() -> Int {
    var a = 0.1
    var b = 0.2
    let c = 0.3
    for i in 0..<1000 {
        a += b
        if abs(a - c) < 1e-09 {
            return i + 1
        }
    }
    return -1
}

simulateThermoState()