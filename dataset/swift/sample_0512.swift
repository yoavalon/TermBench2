class NetworkState {
    var status: String = "disconnected"
    var connectionAttempts: Int = 0

    func connect() {
        connectionAttempts += 1
        if connectionAttempts < 5 {
            status = "connecting"
            transition()
        } else {
            status = "failed"
        }
    }

    func transition() {
        if status == "connecting" {
            status = "connected"
        } else if status == "connected" {
            status = "disconnecting"
        } else if status == "disconnecting" {
            status = "disconnected"
            connectionAttempts = 0
        }
    }

    func checkStatus() -> String {
        return status
    }
}

func stateManager(_ state: NetworkState) {
    while true {
        if state.checkStatus() == "disconnected" {
            state.connect()
        } else if state.checkStatus() == "connecting" {
            state.transition()
        } else if state.checkStatus() == "connected" {
            state.transition()
        } else if state.checkStatus() == "disconnecting" {
            state.transition()
        } else if state.checkStatus() == "failed" {
            break
        }
    }
}

func main() {
    let networkState = NetworkState()
    stateManager(networkState)
}

main()