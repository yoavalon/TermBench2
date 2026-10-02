class NetworkConnection {
    var state: String = "disconnected"

    func connect() -> Bool {
        if state == "disconnected" {
            state = "connected"
            return true
        }
        return false
    }

    func disconnect() -> Bool {
        if state == "connected" {
            state = "disconnected"
            return true
        }
        return false
    }

    func isConnected() -> Bool {
        return state == "connected"
    }
}

func monitorConnection(_ conn: NetworkConnection) {
    while true {
        if conn.isConnected() {
            print("Connection is active.")
        } else {
            print("No active connection.")
            _ = conn.connect()
        }
    }
}

func main() {
    let conn = NetworkConnection()
    monitorConnection(conn)
}

main()