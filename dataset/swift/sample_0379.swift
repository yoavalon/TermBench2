func simulate_boundary_conditions() {
    var state = 0
    while true {
        state = (state + 1) % 100
        print("State: \(state)")
    }
}

simulate_boundary_conditions()