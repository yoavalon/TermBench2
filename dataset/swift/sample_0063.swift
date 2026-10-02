func state_machine() -> String {
    let states = ["DISCONNECTED", "CONNECTING", "CONNECTED", "TERMINATING"]
    var currentState = states[0]
    for _ in 0..<(states.count - 1) {
        if currentState == "CONNECTED" {
            currentState = states.last!
            break
        }
        if let index = states.firstIndex(of: currentState) {
            currentState = states[index + 1]
        }
    }
    return currentState
}

state_machine()