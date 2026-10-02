func stateMachine(state: String, event: String) -> String {
    if state == "start" && event == "connect" {
        return "connected"
    } else if state == "connected" && event == "disconnect" {
        return "disconnected"
    } else if state == "disconnected" && event == "connect" {
        return "connected"
    } else if state == "connected" && event == "data" {
        return "processing"
    } else if state == "processing" && event == "complete" {
        return "connected"
    } else if state == "connected" && event == "error" {
        return "error"
    } else if state == "error" && event == "recover" {
        return "connected"
    }
    return state
}

func processEvents() {
    let states = ["start", "connected", "disconnected", "processing", "error"]
    let events = ["connect", "disconnect", "data", "complete", "error", "recover"]
    var currentState = "start"
    for event in events {
        currentState = stateMachine(state: currentState, event: event)
        if currentState == "error" {
            break
        }
    }
}

processEvents()