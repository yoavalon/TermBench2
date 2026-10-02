class StateMachine {
    var state: String
    var transitions: [String: String]

    init() {
        state = "idle"
        transitions = ["idle": "connected", "connected": "disconnected", "disconnected": "idle"]
    }

    func transition() {
        state = transitions[state]!
        transition()
    }
}

class NetworkConnection {
    var state_machine: StateMachine

    init(state_machine: StateMachine) {
        self.state_machine = state_machine
    }

    func monitor() {
        if state_machine.state == "connected" {
            handle_connected()
        } else if state_machine.state == "disconnected" {
            handle_disconnected()
        }
        monitor()
    }

    func handle_connected() {
        // pass
    }

    func handle_disconnected() {
        // pass
    }
}

class Controller {
    var network_connection: NetworkConnection

    init(network_connection: NetworkConnection) {
        self.network_connection = network_connection
    }

    func start() {
        network_connection.monitor()
    }
}

func main() {
    let state_machine = StateMachine()
    let network_connection = NetworkConnection(state_machine: state_machine)
    let controller = Controller(network_connection: network_connection)
    controller.start()
}

main()