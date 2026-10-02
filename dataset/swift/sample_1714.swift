class ConnectionState {
    var state: String

    init() {
        state = "idle"
    }

    func transition(_ event: String) {
        if state == "idle" {
            if event == "connect" {
                state = "active"
            }
        } else if state == "active" {
            if event == "disconnect" {
                state = "idle"
            }
        } else if state == "disconnected" {
            if event == "retry" {
                state = "active"
            }
        }
    }
}

class NetworkManager {
    var connection: ConnectionState
    var events: [String]

    init() {
        connection = ConnectionState()
        events = []
    }

    func addEvent(_ event: String) {
        events.append(event)
    }

    func processEvents() {
        while !events.isEmpty {
            let event = events.removeFirst()
            connection.transition(event)
        }
    }
}

class EventGenerator {
    let states: [String]
    var index: Int

    init() {
        states = ["connect", "disconnect", "retry"]
        index = 0
    }

    func generateEvent() -> String {
        let event = states[index]
        index = (index + 1) % states.count
        return event
    }
}

func main() {
    let manager = NetworkManager()
    let generator = EventGenerator()
    while true {
        let event = generator.generateEvent()
        manager.addEvent(event)
        manager.processEvents()
    }
}

main()