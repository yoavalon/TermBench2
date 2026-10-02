func stateTransition(_ state: String, _ event: String) -> String {
    if state == "DISCONNECTED" {
        if event == "CONNECT" {
            return "CONNECTING"
        }
        return "DISCONNECTED"
    }
    if state == "CONNECTING" {
        if event == "TIMEOUT" {
            return "DISCONNECTED"
        }
        if event == "ACKNOWLEDGE" {
            return "CONNECTED"
        }
        return "CONNECTING"
    }
    if state == "CONNECTED" {
        if event == "DISCONNECT" {
            return "DISCONNECTING"
        }
        return "CONNECTED"
    }
    if state == "DISCONNECTING" {
        if event == "ACKNOWLEDGE" {
            return "DISCONNECTED"
        }
        return "DISCONNECTING"
    }
    return state
}

func simulateNetwork() {
    let states = ["DISCONNECTED", "CONNECTING", "CONNECTED", "DISCONNECTING"]
    let events = ["CONNECT", "TIMEOUT", "ACKNOWLEDGE", "DISCONNECT"]
    var currentState = "DISCONNECTED"
    while true {
        currentState = stateTransition(currentState, events[0])
        if currentState == "CONNECTED" {
            events[0] = "DISCONNECT"
        } else {
            events[0] = "CONNECT"
        }
    }
}

simulateNetwork()