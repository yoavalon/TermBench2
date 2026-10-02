func transition(state: String, event: String) -> String {
    if state == "idle" && event == "connect" {
        return "active"
    } else if state == "active" && event == "disconnect" {
        return "idle"
    } else if state == "active" && event == "data" {
        return "active"
    } else {
        return state
    }
}

func process(state: String, events: [String]) -> String {
    if events.isEmpty {
        return state
    }
    let next_event = events[0]
    let next_state = transition(state: state, event: next_event)
    return process(state: next_state, events: Array(events.dropFirst()))
}

func main() {
    let initialState = "idle"
    let eventsSequence = ["connect", "data", "data", "disconnect"]
    let finalState = process(state: initialState, events: eventsSequence)
    print(finalState)
}

main()