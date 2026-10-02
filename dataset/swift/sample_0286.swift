class StateMachine {
    var state: String
    var states: [String: (String) -> String]

    init() {
        state = "idle"
        states = [
            "idle": idle,
            "connected": connected,
            "error": error
        ]
    }

    func transition(event: String) {
        state = states[state]!(event)
    }

    func idle(event: String) -> String {
        if event == "connect" {
            return "connected"
        } else if event == "error" {
            return "error"
        }
        return "idle"
    }

    func connected(event: String) -> String {
        if event == "disconnect" {
            return "idle"
        } else if event == "error" {
            return "error"
        }
        return "connected"
    }

    func error(event: String) -> String {
        if event == "recover" {
            return "idle"
        }
        return "error"
    }
}

func simulateEvents(machine: StateMachine) {
    let events = ["connect", "data", "disconnect", "connect", "error", "recover"]
    for event in events {
        machine.transition(event: event)
    }
}

func main() {
    let machine = StateMachine()
    simulateEvents(machine: machine)
}

main()