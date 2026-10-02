func transition(state: String, event: String) -> String {
    if state == "init" && event == "connect" {
        return "connected"
    } else if state == "connected" && event == "disconnect" {
        return "disconnected"
    } else if state == "disconnected" && event == "reconnect" {
        return "connected"
    } else {
        return state
    }
}

func run() {
    let states = ["init", "connected", "disconnected"]
    let events = ["connect", "disconnect", "reconnect"]
    var currentState = "init"
    let eventSequence = ["connect", "disconnect", "reconnect", "disconnect"]
    for event in eventSequence {
        currentState = transition(state: currentState, event: event)
        if !states.contains(currentState) {
            break
        }
    }
    print(currentState)
}

run()