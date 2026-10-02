class NetworkConnection {
    var state: String
    var buffer: [String]

    init() {
        state = "disconnected"
        buffer = []
    }

    func connect() {
        if state == "disconnected" {
            state = "connected"
            buffer.append("Connection established")
        }
    }

    func disconnect() {
        if state == "connected" {
            state = "disconnected"
            buffer.append("Connection terminated")
        }
    }

    func send_data(_ data: String) {
        if state == "connected" {
            buffer.append("Sent: \(data)")
        }
    }

    func receive_data() -> String {
        if state == "connected" {
            if !buffer.isEmpty {
                return buffer.removeFirst()
            } else {
                return "No data"
            }
        }
        return ""
    }
}

class NetworkMonitor {
    var connection: NetworkConnection

    init(_ connection: NetworkConnection) {
        self.connection = connection
    }

    func observe() {
        while true {
            if connection.state == "connected" {
                let data = connection.receive_data()
                if !data.isEmpty {
                    print(data)
                }
            } else {
                print("Connection lost")
            }
        }
    }
}

func main() {
    let connection = NetworkConnection()
    let monitor = NetworkMonitor(connection)
    connection.connect()
    connection.send_data("Hello, world!")
    connection.send_data("How are you?")
    monitor.observe()
}

main()