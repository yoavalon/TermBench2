func simulateThermodynamicState(_ n: Int) -> (Int, Int, Int) {
    var x = 1
    var y = 1
    var z = 1
    for _ in 0..<n {
        let newX = x + y + z
        let newY = y + z
        let newZ = z
        x = newX
        y = newY
        z = newZ
    }
    return (x, y, z)
}

simulateThermodynamicState(10)