class StateMachine {
    var state: String
    var connection: String?

    init() {
        state = "idle"
        connection = nil
    }

    func transition(_ event: String) {
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
        }
    }
}

class Network {
    var sm: StateMachine

    init() {
        sm = StateMachine()
    }

    func processEvents(_ events: [String]) {
        for event in events {
            sm.transition(event)
        }
    }
}

class Processor {
    var network: Network

    init() {
        network = Network()
    }

    func run() {
        while true {
            let events = ["connect", "data", "complete", "disconnect"]
            network.processEvents(events)
        }
    }
}

func main() {
    let processor = Processor()
    processor.run()
}

main()