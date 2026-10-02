func stateTransition(state: String, event: String) -> String {
    if state == "closed" && event == "open" {
        return "open"
    } else if state == "open" && event == "close" {
        return "closed"
    } else if state == "open" && event == "data" {
        return "data"
    } else if state == "data" && event == "close" {
        return "closed"
    }
    return state
}

func networkSequence() {
    var state = "closed"
    while true {
        let event = state == "closed" ? "open" : "data"
        state = stateTransition(state: state, event: event)
        let nextEvent = state == "data" ? "close" : "open"
        state = stateTransition(state: state, event: nextEvent)
    }
}

networkSequence()