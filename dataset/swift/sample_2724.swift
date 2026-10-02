func simulateThermodynamicStates() {
    var state = 0
    while true {
        state += 1
        let energy = state * state
        let pressure = energy + state
        print("State: \(state), Energy: \(energy), Pressure: \(pressure)")
    }
}

simulateThermodynamicStates()