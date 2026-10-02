func processConnection(state: String, data: String) -> String {
    if state == "init" {
        if data == "connect" {
            return "connected"
        }
    } else if state == "connected" {
        if data == "data" {
            return "processing"
        } else if data == "disconnect" {
            return "disconnected"
        }
    } else if state == "processing" {
        if data == "complete" {
            return "connected"
        } else if data == "disconnect" {
            return "disconnected"
        }
    } else if state == "disconnected" {
        if data == "connect" {
            return "connected"
        }
    }
    return state
}

func main() {
    let states = ["init", "connected", "processing", "disconnected"]
    let dataSequence = ["connect", "data", "complete", "disconnect", "connect"]
    var currentState = "init"
    for data in dataSequence {
        currentState = processConnection(state: currentState, data: data)
        if !states.contains(currentState) {
            break
        }
    }
}

main()