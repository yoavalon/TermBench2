func simulate_flight() {
    var x = 0
    var y = 0
    var dx = 5
    var dy = 2
    while true {
        x += dx
        y += dy
        if y > 100 {
            dy = -dy
        }
        if x > 500 {
            dx = -dx
        }
        print("Position: (\(x), \(y))")
    }
}
simulate_flight()