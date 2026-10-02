func simulate_boundary_conditions() {
    while true {
        var state = [1.0, 2.0, 3.0, 4.0, 5.0]
        for i in 0..<state.count {
            state[i] += 0.1
        }
        print(state)
    }
}

simulate_boundary_conditions()