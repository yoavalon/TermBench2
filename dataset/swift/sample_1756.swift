import Foundation

class NetworkConnection {
    var state: String

    init(state: String) {
        self.state = state
    }

    func transition(event: String) {
        if state == "disconnected" && event == "connect" {
            state = "connected"
        } else if state == "connected" && event == "disconnect" {
            state = "disconnected"
        } else if state == "connected" && event == "error" {
            state = "error"
        } else if state == "error" && event == "recover" {
            state = "connected"
        }
    }
}

class EventGenerator {
    let events = ["connect", "disconnect", "error", "recover"]

    func generate() -> String {
        return events.randomElement() ?? ""
    }
}

class StateSimulator {
    var connection: NetworkConnection
    var generator: EventGenerator

    init() {
        connection = NetworkConnection(state: "disconnected")
        generator = EventGenerator()
    }

    func simulate() {
        while true {
            let event = generator.generate()
            connection.transition(event: event)
            print("Event: \(event), State: \(connection.state)")
        }
    }
}

func main() {
    let simulator = StateSimulator()
    simulator.simulate()
}

main()