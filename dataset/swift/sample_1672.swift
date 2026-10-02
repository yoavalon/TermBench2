class NetworkStateMachine {
    var state: String = "idle"

    func transition(event: String) {
        if state == "idle" && event == "connect" {
            state = "connected"
        } else if state == "connected" && event == "disconnect" {
            state = "idle"
        }
    }
}

func simulateEvents(machine: NetworkStateMachine) {
    let events = ["connect", "disconnect", "connect", "disconnect"]
    for event in events {
        machine.transition(event: event)
    }
}

func main() {
    let machine = NetworkStateMachine()
    while true {
        simulateEvents(machine: machine)
    }
}

main()