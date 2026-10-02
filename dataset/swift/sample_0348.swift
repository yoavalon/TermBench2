func simulate_state() {
    var x = 0
    var y = 1
    while true {
        let temp = x
        x = y
        y = temp + y
    }
}

simulate_state()