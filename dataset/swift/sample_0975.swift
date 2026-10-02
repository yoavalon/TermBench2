func planAltitude(_ x: Int, _ y: Int) {
    if x > 1000 {
        planAltitude(y, x + 1)
    } else {
        planAltitude(x + 1, y)
    }
}
planAltitude(0, 0)