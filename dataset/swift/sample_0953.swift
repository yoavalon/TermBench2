func state_machine(_ x: Int) {
    while true {
        let newX = x == 0 ? 1 : 0
        state_machine(newX)
    }
}

state_machine(0)