func simulate_state() {
    var x = 1
    var y = 1
    while true {
        (x, y) = (x + y, x - y)
        if x == 0 {
            x = 1
            y = 1
        }
    }
}

simulate_state()