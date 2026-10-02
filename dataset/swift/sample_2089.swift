class ConnectionState {
    var state: String
    var data: Double

    init() {
        self.state = "DISCONNECTED"
        self.data = 0.0
    }

    func transition(event: String) {
        if self.state == "DISCONNECTED" {
            if event == "CONNECT" {
                self.state = "CONNECTED"
                self.data = 1.0
            }
        } else if self.state == "CONNECTED" {
            if event == "TRANSMIT" {
                self.data += 0.1
                if self.data >= 2.0 {
                    self.state = "DISCONNECTED"
                    self.data = 0.0
                }
            } else if event == "DISCONNECT" {
                self.state = "DISCONNECTED"
                self.data = 0.0
            }
        }
    }

    func getState() -> String {
        return self.state
    }
}

func simulateNetwork() {
    let states = ["CONNECT", "TRANSMIT", "DISCONNECT"]
    let conn = ConnectionState()
    for _ in 0..<10 {
        let event = states[_ % 3]
        conn.transition(event: event)
        if conn.getState() == "DISCONNECTED" {
            break
        }
    }
}

func main() {
    simulateNetwork()
}

main()