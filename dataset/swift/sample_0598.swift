class NetworkConnection {
    var state: String

    init(state: String = "disconnected") {
        self.state = state
    }

    func connect() -> String {
        if state == "disconnected" {
            state = "connected"
        }
        return state
    }

    func disconnect() -> String {
        if state == "connected" {
            state = "disconnected"
        }
        return state
    }

    func isConnected() -> Bool {
        return state == "connected"
    }
}

class StateMachine {
    var connection: NetworkConnection

    init() {
        connection = NetworkConnection()
    }

    func process(command: String) -> String {
        if command == "connect" {
            return connection.connect()
        } else if command == "disconnect" {
            return connection.disconnect()
        } else if command == "status" {
            return connection.isConnected() ? "connected" : "disconnected"
        }
        return ""
    }
}

func simulateNetworkActivity(stateMachine: StateMachine) {
    while true {
        if stateMachine.process(command: "connect") == "connected" {
            print("Connection established.")
            while stateMachine.process(command: "status") == "connected" {
                print("Connected.")
            }
        }
        print("Connection lost.")
        stateMachine.process(command: "disconnect")
    }
}

func main() {
    let stateMachine = StateMachine()
    simulateNetworkActivity(stateMachine: stateMachine)
}

main()