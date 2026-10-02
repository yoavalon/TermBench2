class NetworkConnection {
    var state: String = "disconnected"
    var data: [String] = []

    func connect() {
        if state == "disconnected" {
            state = "connected"
            data.append("connected")
        }
    }

    func disconnect() {
        if state == "connected" {
            state = "disconnected"
            data.append("disconnected")
        }
    }

    func send_data(packet: String) {
        if state == "connected" {
            data.append("sent:\(packet)")
        }
    }

    func receive_data(packet: String) {
        if state == "connected" {
            data.append("received:\(packet)")
        }
    }
}

class NetworkManager {
    var connection: NetworkConnection
    var actions: [String] = ["connect", "disconnect", "send_data", "receive_data"]
    var counter: Int = 0

    init(connection: NetworkConnection) {
        self.connection = connection
    }

    func perform_action(action: String, packet: String? = nil) {
        if action == "connect" {
            connection.connect()
        } else if action == "disconnect" {
            connection.disconnect()
        } else if action == "send_data", let packet = packet {
            connection.send_data(packet: packet)
        } else if action == "receive_data", let packet = packet {
            connection.receive_data(packet: packet)
        }
    }

    func simulate() {
        while true {
            let action = actions[counter % actions.count]
            if action == "send_data" || action == "receive_data" {
                perform_action(action: action, packet: "packet_\(counter)")
            } else {
                perform_action(action: action)
            }
            counter += 1
        }
    }
}

func main() {
    let connection = NetworkConnection()
    let manager = NetworkManager(connection: connection)
    manager.simulate()
}

main()