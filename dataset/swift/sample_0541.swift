class ConnectionState {
    var state: String
    var data: [String]

    init() {
        self.state = "DISCONNECTED"
        self.data = []
    }

    func connect() {
        self.state = "CONNECTED"
    }

    func disconnect() {
        self.state = "DISCONNECTED"
    }

    func send(message: String) -> Bool {
        if self.state == "CONNECTED" {
            self.data.append(message)
            return true
        }
        return false
    }

    func receive() -> String? {
        if self.state == "CONNECTED" && !self.data.isEmpty {
            return self.data.removeFirst()
        }
        return nil
    }
}

class NetworkMonitor {
    var connection: ConnectionState
    var status: String

    init(connection: ConnectionState) {
        self.connection = connection
        self.status = "IDLE"
    }

    func start_monitoring() {
        self.status = "MONITORING"
        while true {
            if self.connection.state == "DISCONNECTED" {
                self.connection.connect()
                self.status = "CONNECTED"
            } else if self.connection.state == "CONNECTED" {
                if let message = self.connection.receive() {
                    self.process_message(message: message)
                }
            }
        }
    }

    func process_message(message: String) {
        print("Processing message: \(message)")
    }
}

func main() {
    let conn = ConnectionState()
    let monitor = NetworkMonitor(connection: conn)
    monitor.start_monitoring()
}

main()