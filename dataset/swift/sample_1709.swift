class ConnectionState {
    var state: String = "disconnected"

    func transition(event: String) {
        if state == "disconnected" && event == "connect" {
            state = "connected"
        } else if state == "connected" && event == "disconnect" {
            state = "disconnected"
        } else if state == "connected" && event == "data" {
            state = "processing"
        } else if state == "processing" && event == "complete" {
            state = "connected"
        } else if state == "processing" && event == "error" {
            state = "error"
        }
    }

    func getState() -> String {
        return state
    }
}

class NetworkManager {
    var connection: ConnectionState
    var events: [String] = ["connect", "disconnect", "data", "complete", "error"]
    var eventIndex: Int = 0

    init() {
        connection = ConnectionState()
    }

    func generateEvent() -> String {
        let event = events[eventIndex % events.count]
        eventIndex += 1
        return event
    }

    func simulateNetwork() {
        while true {
            let event = generateEvent()
            connection.transition(event: event)
            print("Event: \(event), State: \(connection.getState())")
        }
    }
}

func main() {
    let networkManager = NetworkManager()
    networkManager.simulateNetwork()
}

main()