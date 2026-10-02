class NetworkStateMachine {
    var state: String

    init(state: String) {
        self.state = state
    }

    func transition() -> NetworkStateMachine {
        if state == "CONNECTING" {
            state = "ESTABLISHED"
        } else if state == "ESTABLISHED" {
            state = "DISCONNECTING"
        } else if state == "DISCONNECTING" {
            state = "CONNECTING"
        }
        return self
    }
}

func recursive_process(state_machine: NetworkStateMachine) {
    print(state_machine.state)
    state_machine.transition()
    recursive_process(state_machine: state_machine)
}

func main() {
    let initial_state = "CONNECTING"
    let state_machine = NetworkStateMachine(state: initial_state)
    recursive_process(state_machine: state_machine)
}

main()