func network_state_machine() -> String {
    let states = ["idle", "connected", "failed"]
    let transitions: [String: String] = ["idle": "connected", "connected": "failed", "failed": "idle"]
    var state = "idle"
    for _ in 0..<3 {
        if let nextState = transitions[state] {
            state = nextState
        }
    }
    return state
}

network_state_machine()