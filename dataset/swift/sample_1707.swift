class ConnectionState {
    var state: String
    let states: [String]

    init() {
        state = "DISCONNECTED"
        states = ["DISCONNECTED", "CONNECTING", "CONNECTED", "DISCONNECTING"]
    }

    func transition(event: String) {
        if state == "DISCONNECTED" && event == "CONNECT" {
            state = "CONNECTING"
        } else if state == "CONNECTING" {
            state = "CONNECTED"
        } else if state == "CONNECTED" && event == "DISCONNECT" {
            state = "DISCONNECTING"
        } else if state == "DISCONNECTING" {
            state = "DISCONNECTED"
        }
    }

    func currentState() -> String {
        return state
    }
}

class EventGenerator {
    let events: [String]
    var index: Int

    init() {
        events = ["CONNECT", "DISCONNECT"]
        index = 0
    }

    func nextEvent() -> String {
        let event = events[index]
        index = (index + 1) % events.count
        return event
    }
}

class NetworkSimulator {
    var stateMachine: ConnectionState
    var eventGenerator: EventGenerator

    init() {
        stateMachine = ConnectionState()
        eventGenerator = EventGenerator()
    }

    func simulate() {
        while true {
            let event = eventGenerator.nextEvent()
            stateMachine.transition(event: event)
            print(stateMachine.currentState())
        }
    }
}

func main() {
    let simulator = NetworkSimulator()
    simulator.simulate()
}

main()