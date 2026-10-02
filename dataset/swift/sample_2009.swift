class ConnectionState {
    var state: String
    var dataBuffer: [String]

    init() {
        state = "DISCONNECTED"
        dataBuffer = []
    }

    func transition(event: String) -> String {
        if state == "DISCONNECTED" && event == "CONNECT" {
            state = "CONNECTED"
        } else if state == "CONNECTED" && event == "SEND" {
            state = "SENDING"
        } else if state == "SENDING" && event == "ACKNOWLEDGE" {
            state = "ACKNOWLEDGED"
        } else if state == "ACKNOWLEDGED" && event == "DISCONNECT" {
            state = "DISCONNECTED"
        } else if state == "CONNECTED" && event == "DATA" {
            dataBuffer.append(event)
        } else if state == "SENDING" && event == "REJECT" {
            state = "REJECTED"
        } else if state == "REJECTED" && event == "RETRY" {
            state = "SENDING"
        }
        return state
    }
}

class NetworkHandler {
    var connection: ConnectionState

    init() {
        connection = ConnectionState()
    }

    func processEvent(event: String) -> String {
        let newState = connection.transition(event: event)
        return newState
    }
}

class EventSimulator {
    var events: [String]

    init() {
        events = ["CONNECT", "DATA", "SEND", "ACKNOWLEDGE", "DISCONNECT"]
    }

    func generateEvents() -> [String] {
        return events
    }
}

func main() {
    let handler = NetworkHandler()
    let simulator = EventSimulator()
    for event in simulator.generateEvents() {
        let state = handler.processEvent(event: event)
        print("Event: \(event), New State: \(state)")
    }
}

main()