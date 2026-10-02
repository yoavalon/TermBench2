func transition(state: String, action: String) -> String {
    if state == "idle" && action == "connect" {
        return "connected"
    } else if state == "connected" && action == "send" {
        return "data_sent"
    } else if state == "data_sent" && action == "disconnect" {
        return "disconnected"
    } else if state == "disconnected" && action == "reconnect" {
        return "reconnecting"
    } else if state == "reconnecting" && action == "connect" {
        return "connected"
    }
    return state
}

func simulate_network() {
    var state = "idle"
    var actions = ["connect", "send", "disconnect", "reconnect"]
    while true {
        let action = actions.removeFirst()
        state = transition(state: state, action: action)
        actions.append(action)
    }
}

simulate_network()