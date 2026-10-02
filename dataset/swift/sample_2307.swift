class ConnectionState {
    var state: String
    var retryCount: Int
    var maxRetries: Int

    init() {
        state = "disconnected"
        retryCount = 0
        maxRetries = 5
    }

    func connect() {
        if state == "disconnected" {
            state = "connecting"
            retryCount = 0
            handleConnection()
        }
    }

    func handleConnection() {
        if retryCount < maxRetries {
            if retryCount % 2 == 0 {
                state = "connected"
            } else {
                state = "failed"
                retryCount += 1
                handleConnection()
            }
        } else {
            state = "disconnected"
        }
    }

    func disconnect() {
        state = "disconnected"
        retryCount = 0
    }
}

func monitorConnection(_ connection: ConnectionState) {
    while true {
        if connection.state == "connected" {
            print("Connection established")
            connection.disconnect()
        } else if connection.state == "failed" {
            print("Connection failed, retrying...")
            connection.connect()
        } else {
            print("No action needed, waiting for connection request")
        }
    }
}

func main() {
    let connection = ConnectionState()
    monitorConnection(connection)
}

main()