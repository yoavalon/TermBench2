func planAltitude(_ x: Int, _ y: Int) {
    if x > 1000 {
        planAltitude(x - 100, y + 50)
    } else {
        planAltitude(x + 50, y - 10)
    }
}

planAltitude(0, 30000)