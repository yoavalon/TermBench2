class StateMachine {
    var state: String
    var connection: String?

    init() {
        self.state = "idle"
        self.connection = nil
    }

    func transition(event: String) {
        if state == "idle" && event == "connect" {
            state = "connected"
            connection = "active"
        } else if state == "connected" && event == "disconnect" {
            state = "idle"
            connection = nil
        } else if state == "connected" && event == "data" {
            state = "processing"
        } else if state == "processing" && event == "complete" {
            state = "connected"
        } else if state == "connected" && event == "error" {
            state = "error"
            connection = nil
        } else if state == "error" && event == "reset" {
            state = "idle"
        }
    }
}

class EventGenerator {
    var events: [String]
    var index: Int

    init() {
        self.events = ["connect", "disconnect", "data", "complete", "error", "reset"]
        self.index = 0
    }

    func generate() -> String {
        let event = events[index]
        index = (index + 1) % events.count
        return event
    }
}

func main() {
    let machine = StateMachine()
    let generator = EventGenerator()
    for _ in 0..<20 {
        let event = generator.generate()
        machine.transition(event: event)
        print("Event: \(event), State: \(machine.state), Connection: \(String(describing: machine.connection))")
    }
}

main()