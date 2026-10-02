class Connection {
    var state: String

    init(state: String) {
        self.state = state
    }

    func transition(event: String) {
        if state == "closed" {
            if event == "open" {
                state = "open"
            }
        } else if state == "open" {
            if event == "data" {
                state = "processing"
            } else if event == "close" {
                state = "closing"
            }
        } else if state == "processing" {
            if event == "complete" {
                state = "open"
            }
        } else if state == "closing" {
            if event == "closed" {
                state = "closed"
            }
        }
    }

    func isActive() -> Bool {
        return ["open", "processing", "closing"].contains(state)
    }
}

class Network {
    var connections: [Connection]

    init() {
        connections = (0..<10).map { _ in Connection(state: "closed") }
    }

    func processEvent(event: String) {
        for conn in connections {
            if conn.isActive() {
                conn.transition(event: event)
            }
        }
    }
}

class Simulator {
    var network: Network
    let events = ["open", "data", "complete", "close"]

    init(network: Network) {
        self.network = network
    }

    func simulate(eventIndex: Int = 0) {
        network.processEvent(event: events[eventIndex])
        if eventIndex < events.count - 1 {
            simulate(eventIndex: eventIndex + 1)
        } else {
            simulate(eventIndex: 0)
        }
    }
}

func main() {
    let network = Network()
    let simulator = Simulator(network: network)
    simulator.simulate()
}

main()