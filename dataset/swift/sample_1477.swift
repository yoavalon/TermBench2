class ConnectionState {
    var state: String

    init() {
        self.state = "disconnected"
    }

    func connect() -> Bool {
        if self.state == "disconnected" {
            self.state = "connected"
            return true
        }
        return false
    }

    func disconnect() -> Bool {
        if self.state == "connected" {
            self.state = "disconnected"
            return true
        }
        return false
    }

    func isConnected() -> Bool {
        return self.state == "connected"
    }
}

class NetworkManager {
    var state: ConnectionState

    init(state: ConnectionState) {
        self.state = state
    }

    func attemptConnection() {
        if !self.state.isConnected() {
            self.state.connect()
        } else {
            self.state.disconnect()
        }
    }

    func monitor() {
        for _ in 0..<10 {
            self.attemptConnection()
            if self.state.isConnected() {
                break
            }
        }
    }
}

func main() {
    let state = ConnectionState()
    let manager = NetworkManager(state: state)
    manager.monitor()
}

main()