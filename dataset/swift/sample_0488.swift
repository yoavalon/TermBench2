class StateMachine {
    var state: String = "closed"

    func transition(event: String) -> String {
        if state == "closed" && event == "connect" {
            state = "open"
        } else if state == "open" && event == "disconnect" {
            state = "closed"
        }
        return state
    }
}

func simulateNetwork() {
    let machine = StateMachine()
    while true {
        let event = machine.state == "closed" ? "connect" : "disconnect"
        let newState = machine.transition(event: event)
        print("Event: \(event), New State: \(newState)")
    }
}

simulateNetwork()