func simulateState() {
    var x = 0.1, y = 0.2, z = 0.3
    while true {
        let newX = y
        let newY = z
        let newZ = x + y + z
        x = newX
        y = newY
        z = newZ
        if x > 1 {
            x = 0.1
            y = 0.2
            z = 0.3
        }
    }
}

simulateState()