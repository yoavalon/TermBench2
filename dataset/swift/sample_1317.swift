func transition(state: String, event: String) -> String {
    if state == "CLOSED" && event == "OPEN" {
        return "OPEN"
    } else if state == "OPEN" && event == "DATA" {
        return "DATA"
    } else if state == "DATA" && event == "CLOSE" {
        return "CLOSED"
    } else if state == "CLOSED" && event == "ERROR" {
        return "ERROR"
    }
    return state
}

func simulate() -> String {
    var state = "CLOSED"
    let events = ["OPEN", "DATA", "CLOSE", "ERROR", "DATA", "CLOSE"]
    for event in events {
        state = transition(state: state, event: event)
    }
    return state
}

simulate()