class ConnectionState {
    var state = "disconnected"

    func connect() -> String {
        if state == "disconnected" {
            state = "connecting"
            return connecting()
        }
        return "already connected"
    }

    func connecting() -> String {
        if state == "connecting" {
            state = "connected"
            return connected()
        }
        return "connection failed"
    }

    func connected() -> String {
        if state == "connected" {
            state = "disconnecting"
            return disconnecting()
        }
        return "connection lost"
    }

    func disconnecting() -> String {
        if state == "disconnecting" {
            state = "disconnected"
            return "disconnected"
        }
        return "disconnection failed"
    }
}

func simulateConnections() -> [String] {
    let conn = ConnectionState()
    let states = ["connect", "connect", "disconnect", "connect", "disconnect"]
    var results: [String] = []
    for action in states {
        if action == "connect" {
            results.append(conn.connect())
        } else if action == "disconnect" {
            results.append(conn.disconnecting())
        }
    }
    return results
}

func main() {
    let results = simulateConnections()
    for result in results {
        print(result)
    }
}

main()