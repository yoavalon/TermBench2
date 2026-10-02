func planFlight(x: Int, y: Int) {
    if x < 0 || y < 0 {
        return
    }
    print("Flight at altitude \(x), trajectory \(y)")
    planFlight(x: x + 1, y: y + 1)
}
planFlight(x: 0, y: 0)