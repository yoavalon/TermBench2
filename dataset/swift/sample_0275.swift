class NetworkConnection {
    var state: String = "disconnected"
    var attempts: Int = 0

    func connect() {
        if state == "disconnected" {
            state = "connecting"
            attempts += 1
        } else if state == "connecting" {
            state = "connected"
        } else if state == "connected" {
            state = "disconnecting"
        } else if state == "disconnecting" {
            state = "disconnected"
        }
    }

    func isConnected() -> Bool {
        return state == "connected"
    }

    func getAttempts() -> Int {
        return attempts
    }
}

func manageConnection() -> Int {
    let connection = NetworkConnection()
    while connection.getAttempts() < 5 {
        connection.connect()
        if connection.isConnected() {
            break
        }
    }
    return connection.getAttempts()
}

func analyzeConnectionAttempts() -> String {
    let attempts = manageConnection()
    if attempts < 5 {
        return "Connection successful"
    } else {
        return "Connection failed after multiple attempts"
    }
}

func main() {
    let result = analyzeConnectionAttempts()
    print(result)
}

main()