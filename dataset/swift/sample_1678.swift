swift
func stateTransition(_ state: String, _ event: String) -> String {
    if state == "disconnected" && event == "connect" {
        return "connected"
    } else if state == "connected" && event == "disconnect" {
        return "disconnected"
    } else if state == "connected" && event == "data_received" {
        return "processing"
    } else if state == "processing" && event == "data_processed" {
        return "connected"
    } else {
        return state
    }
}

func simulateNetwork() {
    var currentState = "disconnected"
    let events = ["connect", "data_received", "data_processed", "disconnect"]
    var index = 0
    while true {
        currentState = stateTransition(currentState, events[index % events.count])
        index += 1
    }
}

simulateNetwork()