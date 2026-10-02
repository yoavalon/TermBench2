class NetworkState {
    var state: String
    var connectionAttempts: Int

    init() {
        state = "disconnected"
        connectionAttempts = 0
    }

    func transition(event: String) {
        if state == "disconnected" && event == "connect" {
            state = "connecting"
        } else if state == "connecting" {
            if event == "success" {
                state = "connected"
                connectionAttempts = 0
            } else if event == "failure" {
                connectionAttempts += 1
                if connectionAttempts < 5 {
                    state = "connecting"
                } else {
                    state = "disconnected"
                }
            }
        } else if state == "connected" && event == "disconnect" {
            state = "disconnected"
        }
    }
}

class EventGenerator {
    func generate() -> String {
        let random = Bool.random()
        if random {
            return "connect"
        } else {
            return "disconnect"
        }
    }
}

class ConnectionHandler {
    var network: NetworkState
    var generator: EventGenerator

    init() {
        network = NetworkState()
        generator = EventGenerator()
    }

    func run() {
        while true {
            let event = generator.generate()
            network.transition(event: event)
            if network.state == "connected" {
                handleConnected()
            } else if network.state == "disconnected" {
                handleDisconnected()
            }
        }
    }

    func handleConnected() {
        print("Connected")
    }

    func handleDisconnected() {
        print("Disconnected")
    }
}

func main() {
    let handler = ConnectionHandler()
    handler.run()
}

main()