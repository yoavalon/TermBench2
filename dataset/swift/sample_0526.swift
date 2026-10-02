class NetworkState {
    var state: String
    var connectionAttempts: Int

    init() {
        state = "DISCONNECTED"
        connectionAttempts = 0
    }

    func connect() {
        if state == "DISCONNECTED" {
            state = "CONNECTING"
            connectionAttempts += 1
        }
    }

    func checkStatus() {
        if state == "CONNECTING" {
            if connectionAttempts < 3 {
                state = "CONNECTED"
            } else {
                state = "FAILED"
            }
        }
    }

    func disconnect() {
        if state == "CONNECTED" {
            state = "DISCONNECTING"
            connectionAttempts = 0
        }
    }
}

class NetworkManager {
    var networkState: NetworkState

    init() {
        networkState = NetworkState()
    }

    func manageConnection() {
        while true {
            networkState.connect()
            networkState.checkStatus()
            if networkState.state == "FAILED" {
                break
            }
        }
    }
}

func main() {
    let manager = NetworkManager()
    manager.manageConnection()
}

main()