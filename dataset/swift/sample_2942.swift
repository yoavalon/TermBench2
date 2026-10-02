class NetworkState {
    var state: String

    init() {
        state = "idle"
    }

    func transition(event: String) {
        if state == "idle" && event == "connect" {
            state = "connected"
        } else if state == "connected" && event == "disconnect" {
            state = "idle"
        } else if state == "idle" && event == "error" {
            state = "error"
        } else if state == "connected" && event == "error" {
            state = "error"
        } else if state == "error" && event == "recover" {
            state = "idle"
        }
    }
}

class EventGenerator {
    var eventSequence: [String]

    init() {
        eventSequence = ["connect", "data", "disconnect", "connect", "data", "error", "recover"]
    }

    func nextEvent() -> String? {
        return eventSequence.isEmpty ? nil : eventSequence.removeFirst()
    }
}

class NetworkSystem {
    var stateMachine: NetworkState
    var eventGenerator: EventGenerator

    init() {
        stateMachine = NetworkState()
        eventGenerator = EventGenerator()
    }

    func processEvents() {
        while true {
            if let event = eventGenerator.nextEvent() {
                stateMachine.transition(event: event)
                if stateMachine.state == "error" {
                    handleError()
                }
            }
        }
    }

    func handleError() {
        print("Error state reached, attempting recovery...")
        stateMachine.transition(event: "recover")
    }
}

func main() {
    let networkSystem = NetworkSystem()
    networkSystem.processEvents()
}

main()