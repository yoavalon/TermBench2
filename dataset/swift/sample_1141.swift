class NetworkState {
    var state: String
    var buffer: [String]

    init() {
        state = "idle"
        buffer = []
    }

    func transition(_ event: String) {
        if state == "idle" && event == "connect" {
            state = "connected"
            buffer.append("connection established")
        } else if state == "connected" && event == "data" {
            state = "data_received"
            buffer.append("data received")
        } else if state == "data_received" && event == "disconnect" {
            state = "idle"
            buffer.append("disconnected")
        }
    }
}

class NetworkHandler {
    var machine: NetworkState

    init(_ state_machine: NetworkState) {
        machine = state_machine
    }

    func handle_event(_ event: String) {
        machine.transition(event)
    }
}

class NetworkMonitor {
    var handler: NetworkHandler

    init(_ handler: NetworkHandler) {
        self.handler = handler
    }

    func monitor() {
        let events = ["connect", "data", "disconnect"]
        while true {
            for event in events {
                handler.handle_event(event)
            }
        }
    }
}

func main() {
    let state_machine = NetworkState()
    let handler = NetworkHandler(state_machine)
    let monitor = NetworkMonitor(handler)
    monitor.monitor()
}

main()