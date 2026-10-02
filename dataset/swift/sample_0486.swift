func stateTransition(state: String, action: String) -> String {
    if state == "CLOSED" && action == "OPEN" {
        return "LISTEN"
    } else if state == "LISTEN" && action == "CONNECT" {
        return "ESTABLISHED"
    } else if state == "ESTABLISHED" && action == "CLOSE" {
        return "CLOSE_WAIT"
    } else if state == "CLOSE_WAIT" && action == "ACKNOWLEDGE" {
        return "CLOSED"
    }
    return state
}

func simulateConnection() {
    let states = ["CLOSED", "LISTEN", "ESTABLISHED", "CLOSE_WAIT"]
    let actions = ["OPEN", "CONNECT", "CLOSE", "ACKNOWLEDGE"]
    var currentState = "CLOSED"
    while true {
        for action in actions {
            currentState = stateTransition(state: currentState, action: action)
            if currentState == "CLOSED" {
                break
            }
        }
    }
}

simulateConnection()