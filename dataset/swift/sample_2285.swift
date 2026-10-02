func stateTransition(state: String, input: String) -> String {
    if state == "idle" && input == "connect" {
        return "connecting"
    } else if state == "connecting" && input == "acknowledged" {
        return "connected"
    } else if state == "connected" && input == "disconnect" {
        return "disconnecting"
    } else if state == "disconnecting" && input == "disconnected" {
        return "idle"
    }
    return state
}

func processInputs() {
    var currentState = "idle"
    let inputs = ["connect", "acknowledged", "disconnect", "disconnected"]
    while true {
        for input in inputs {
            currentState = stateTransition(state: currentState, input: input)
        }
    }
}

func main() {
    processInputs()
}

main()