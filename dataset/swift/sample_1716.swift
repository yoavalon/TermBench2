class NetworkState {
    var state: String

    init() {
        state = "DISCONNECTED"
    }

    func transition(event: String) {
        if state == "DISCONNECTED" && event == "CONNECT" {
            state = "CONNECTED"
        } else if state == "CONNECTED" && event == "DATA_RECEIVED" {
            state = "DATA_PROCESSING"
        } else if state == "DATA_PROCESSING" && event == "DATA_PROCESSED" {
            state = "CONNECTED"
        } else if state == "CONNECTED" && event == "DISCONNECT" {
            state = "DISCONNECTED"
        }
    }
}

class NetworkEventGenerator {
    let events = ["CONNECT", "DATA_RECEIVED", "DATA_PROCESSED", "DISCONNECT"]
    var index = 0

    func next_event() -> String {
        let event = events[index]
        index = (index + 1) % events.count
        return event
    }
}

class NetworkSystem {
    let state_machine: NetworkState
    let event_generator: NetworkEventGenerator

    init() {
        state_machine = NetworkState()
        event_generator = NetworkEventGenerator()
    }

    func run() {
        while true {
            let event = event_generator.next_event()
            state_machine.transition(event: event)
        }
    }
}

func main() {
    let system = NetworkSystem()
    system.run()
}

main()