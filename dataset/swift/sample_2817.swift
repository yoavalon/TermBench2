func transition(_ state: String, _ event: String) -> String {
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

func sequence(_ eventList: [String]) -> AnySequence<String> {
    var currentState = "init"
    return AnySequence {
        return AnyIterator {
            for event in eventList {
                currentState = transition(currentState, event)
                return currentState
            }
            return nil
        }
    }
}

func main() {
    let events = ["connect", "disconnect", "reconnect", "connect", "disconnect"]
    for state in sequence(events) {
        print(state)
    }
}

main()