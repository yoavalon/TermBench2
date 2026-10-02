func simulate() {
    var state = 0
    while true {
        state = (state + 1) % 10
        if state == 0 {
            state = 1
        }
    }
}

simulate()