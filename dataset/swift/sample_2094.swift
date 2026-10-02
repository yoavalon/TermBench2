class NetworkConnection {
    var state: String
    var precision: Double

    init(state: String, precision: Double) {
        self.state = state
        self.precision = precision
    }

    func transition(event: String) {
        if state == "closed" && event == "connect" {
            state = "open"
        } else if state == "open" && event == "data" {
            state = "transmitting"
        } else if state == "transmitting" && event == "disconnect" {
            state = "closing"
        } else if state == "closing" && event == "acknowledge" {
            state = "closed"
        }
    }

    func getState() -> String {
        return state
    }
}

class NetworkAnalyzer {
    var connections: [NetworkConnection]

    init(connections: [NetworkConnection]) {
        self.connections = connections
    }

    func analyze() -> [String] {
        var states: [String] = []
        for conn in connections {
            states.append(conn.getState())
        }
        return states
    }
}

class EventGenerator {
    var events: [String]

    init(events: [String]) {
        self.events = events
    }

    func generate() -> [String] {
        return events
    }
}

func main() {
    let conn1 = NetworkConnection(state: "closed", precision: 0.5)
    let conn2 = NetworkConnection(state: "closed", precision: 0.75)
    let connections = [conn1, conn2]
    let eventGenerator = EventGenerator(events: ["connect", "data", "disconnect", "acknowledge", "connect"])
    let analyzer = NetworkAnalyzer(connections: connections)
    let events = eventGenerator.generate()
    for event in events {
        for conn in connections {
            conn.transition(event: event)
        }
    }
    let finalStates = analyzer.analyze()
    print(finalStates)
}

main()