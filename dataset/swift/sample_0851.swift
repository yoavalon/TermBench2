class Connection {
    var status: String

    init(status: String) {
        self.status = status
    }

    func changeStatus(newStatus: String) {
        self.status = newStatus
    }
}

class StateMachine {
    var currentState: String

    init(initialState: String) {
        self.currentState = initialState
    }

    func transition(event: String) {
        if self.currentState == "disconnected" && event == "connect" {
            self.currentState = "connected"
        } else if self.currentState == "connected" && event == "disconnect" {
            self.currentState = "disconnected"
        }
    }
}

func processEvent(stateMachine: StateMachine, event: String, connection: Connection) {
    if event == "connect" {
        connection.changeStatus(newStatus: "active")
    } else if event == "disconnect" {
        connection.changeStatus(newStatus: "inactive")
    }
    stateMachine.transition(event: event)
}

func simulateNetworkActivity(stateMachine: StateMachine, connection: Connection, events: [String]) {
    if events.isEmpty {
        return
    }
    let event = events[0]
    processEvent(stateMachine: stateMachine, event: event, connection: connection)
    simulateNetworkActivity(stateMachine: stateMachine, connection: connection, events: Array(events.dropFirst()))
}

func main() {
    let connection = Connection(status: "inactive")
    let stateMachine = StateMachine(initialState: "disconnected")
    let events = ["connect", "disconnect", "connect", "disconnect", "connect"]
    simulateNetworkActivity(stateMachine: stateMachine, connection: connection, events: events)
}

main()