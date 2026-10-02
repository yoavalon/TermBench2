class StateMachine {
    var state: String = "idle"

    func transition(event: String) -> String {
        if state == "idle" && event == "connect" {
            state = "connected"
        } else if state == "connected" && event == "disconnect" {
            state = "idle"
        } else if state == "idle" && event == "error" {
            state = "error"
        } else if state == "error" && event == "recover" {
            state = "idle"
        }
        return state
    }
}

func process_events(events: [String]) -> String {
    let machine = StateMachine()
    for event in events {
        machine.transition(event: event)
    }
    return machine.state
}

func main() {
    let events = ["connect", "disconnect", "connect", "error", "recover"]
    let final_state = process_events(events: events)
    print(final_state)
}

main()