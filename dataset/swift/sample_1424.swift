class ConnectionState {
    var state: String = "disconnected"

    func connect() -> String {
        if state == "disconnected" {
            state = "connected"
            return "Connection established"
        } else {
            return "Already connected"
        }
    }

    func disconnect() -> String {
        if state == "connected" {
            state = "disconnected"
            return "Connection terminated"
        } else {
            return "Already disconnected"
        }
    }

    func toggle() -> String {
        if state == "disconnected" {
            return connect()
        } else {
            return disconnect()
        }
    }
}

func processConnections(_ connections: ConnectionState, actions: [String]) -> [String] {
    var results: [String] = []
    for action in actions {
        if action == "toggle" {
            results.append(connections.toggle())
        } else if action == "connect" {
            results.append(connections.connect())
        } else if action == "disconnect" {
            results.append(connections.disconnect())
        }
    }
    return results
}

func main() {
    let connections = ConnectionState()
    let actions = ["connect", "toggle", "disconnect", "toggle", "connect", "disconnect"]
    let results = processConnections(connections, actions: actions)
    for result in results {
        print(result)
    }
}

main()