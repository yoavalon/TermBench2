func transition(state: String, event: String) -> String {
    if state == "init" && event == "connect" {
        return "connected"
    } else if state == "connected" && event == "data" {
        return "transmitting"
    } else if state == "transmitting" && event == "disconnect" {
        return "disconnected"
    } else {
        return state
    }
}

func sequence() {
    var state = "init"
    let events = ["connect", "data", "disconnect", "connect", "data", "disconnect"]
    while true {
        for event in events {
            state = transition(state: state, event: event)
            print(state)
        }
    }
}

func main() {
    sequence()
}

main()