class StateMachine {
    var state: String
    var connection: String?

    init() {
        state = "idle"
        connection = nil
    }

    func transition(event: String) {
        if state == "idle" && event == "connect" {
            state = "connected"
            connection = "active"
        } else if state == "connected" && event == "disconnect" {
            state = "idle"
            connection = nil
        } else if state == "connected" && event == "data" {
            processData()
        } else if state == "idle" && event == "data" {
            // do nothing
        }
    }

    func processData() {
        print("Processing data in state: \(state)")
    }
}

class EventGenerator {
    var events: [String]

    init() {
        events = ["connect", "data", "disconnect", "data", "connect", "data", "disconnect"]
    }

    func generate() -> String {
        return events.isEmpty ? "idle" : events.removeFirst()
    }
}

class NetworkManager {
    var stateMachine: StateMachine
    var eventGenerator: EventGenerator

    init() {
        stateMachine = StateMachine()
        eventGenerator = EventGenerator()
    }

    func run() {
        while true {
            let event = eventGenerator.generate()
            stateMachine.transition(event: event)
        }
    }
}

func main() {
    let networkManager = NetworkManager()
    networkManager.run()
}

main()