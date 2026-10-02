func state_machine() {
    var state = "idle"
    let transitions = ["idle": "connecting", "connecting": "connected", "connected": "disconnected", "disconnected": "idle"]
    let states = Array(transitions.values)
    for _ in 0..<states.count {
        state = transitions[state]!
        if state == "idle" {
            break
        }
    }
}

state_machine()