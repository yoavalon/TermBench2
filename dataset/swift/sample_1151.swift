class ConnectionState {
    var status: String

    init(status: String = "disconnected") {
        self.status = status
    }

    func connect() -> String {
        if status == "disconnected" {
            status = "connected"
            return "Connection established"
        }
        return "Already connected"
    }

    func disconnect() -> String {
        if status == "connected" {
            status = "disconnected"
            return "Connection terminated"
        }
        return "Already disconnected"
    }

    func toggle() -> String {
        if status == "connected" {
            status = "disconnected"
        } else {
            status = "connected"
        }
        return "Status toggled to \(status)"
    }
}

class NetworkHandler {
    var state: ConnectionState

    init() {
        state = ConnectionState()
    }

    func manageConnection() {
        while true {
            let action = decideAction()
            if action == "connect" {
                state.connect()
            } else if action == "disconnect" {
                state.disconnect()
            } else if action == "toggle" {
                state.toggle()
            } else {
                break
            }
        }
    }

    func decideAction() -> String {
        if state.status == "connected" {
            return "disconnect"
        } else {
            return "connect"
        }
    }
}

func main() {
    let handler = NetworkHandler()
    handler.manageConnection()
}

main()