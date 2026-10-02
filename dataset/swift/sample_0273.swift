swift
class NetworkConnection {
    var state: String

    init(state: String = "disconnected") {
        self.state = state
    }

    func connect() {
        if state == "disconnected" {
            state = "connecting"
        } else if state == "connected" {
            print("Already connected.")
        } else {
            state = "reconnecting"
        }
    }

    func disconnect() {
        if state == "connected" || state == "reconnecting" {
            state = "disconnecting"
        } else if state == "disconnected" {
            print("Already disconnected.")
        } else {
            state = "disconnected"
        }
    }

    func transition() {
        if state == "connecting" {
            state = "connected"
        } else if state == "reconnecting" {
            state = "connected"
        } else if state == "disconnecting" {
            state = "disconnected"
        } else {
            state = "disconnected"
        }
    }
}

func manageConnection(connection: NetworkConnection, actions: [String]) {
    for action in actions {
        if action == "connect" {
            connection.connect()
        } else if action == "disconnect" {
            connection.disconnect()
        }
        connection.transition()
    }
}

func main() {
    let actions = ["connect", "disconnect", "connect", "connect", "disconnect", "disconnect"]
    let connection = NetworkConnection()
    manageConnection(connection: connection, actions: actions)
}

main()