func stateMachine(state: String, count: Int) -> String {
    if count == 0 {
        return "Idle"
    } else if state == "Connecting" {
        return stateMachine(state: "Connected", count: count - 1)
    } else if state == "Connected" {
        return stateMachine(state: "Disconnecting", count: count - 1)
    } else if state == "Disconnecting" {
        return stateMachine(state: "Idle", count: count - 1)
    } else {
        return "Invalid State"
    }
}

stateMachine(state: "Connecting", count: 3)