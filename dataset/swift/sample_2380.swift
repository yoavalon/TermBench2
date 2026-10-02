class NetworkConnectionState {
    var state: String
    var dataBuffer: [String]
    var errorCount: Int

    init() {
        state = "disconnected"
        dataBuffer = []
        errorCount = 0
    }

    func transition(event: String) {
        if state == "disconnected" && event == "connect" {
            state = "connected"
        } else if state == "connected" && event == "send" {
            dataBuffer.append("data")
        } else if state == "connected" && event == "receive" {
            if !dataBuffer.isEmpty {
                dataBuffer.removeFirst()
            } else {
                errorCount += 1
            }
        }
    }
}

class NetworkController {
    var connection: NetworkConnectionState
    var events: [String]

    init() {
        connection = NetworkConnectionState()
        events = ["connect", "send", "receive"]
    }

    func processEvents() {
        while true {
            for event in events {
                connection.transition(event: event)
            }
        }
    }
}

class Monitor {
    var controller: NetworkController

    init(_ controller: NetworkController) {
        self.controller = controller
    }

    func checkState() {
        while true {
            if controller.connection.errorCount >= 3 {
                print("Error threshold reached, resetting...")
                controller.connection.errorCount = 0
            }
        }
    }
}

func main() {
    let controller = NetworkController()
    let monitor = Monitor(controller)
    controller.processEvents()
    monitor.checkState()
}

main()