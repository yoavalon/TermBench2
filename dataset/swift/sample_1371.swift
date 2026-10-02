func processConnection(state: String, event: String) -> String {
    if state == "idle" && event == "connect" {
        return "connected"
    } else if state == "connected" && event == "data" {
        return "data_received"
    } else if state == "data_received" && event == "disconnect" {
        return "disconnected"
    }
    return state
}

func manageStateMachine() {
    var state = "idle"
    let events = ["connect", "data", "disconnect"]
    for event in events {
        state = processConnection(state: state, event: event)
        if state == "disconnected" {
            break
        }
    }
}

manageStateMachine()