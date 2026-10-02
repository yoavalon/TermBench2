func transition(state: String, event: String) -> String {
    if state == "idle" && event == "connect" {
        return "connected"
    } else if state == "connected" && event == "data" {
        return "data_received"
    } else if state == "data_received" && event == "disconnect" {
        return "disconnected"
    } else {
        return state
    }
}

func processEvents(events: [String]) -> String {
    var currentState = "idle"
    for event in events {
        currentState = transition(state: currentState, event: event)
        if currentState == "disconnected" {
            break
        }
    }
    return currentState
}

func main() {
    let events = ["connect", "data", "disconnect", "connect"]
    let finalState = processEvents(events: events)
    print(finalState)
}

main()