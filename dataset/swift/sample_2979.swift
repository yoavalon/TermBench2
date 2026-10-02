class NetworkState {
    var state = 0

    func transition() {
        if state == 0 {
            state = 1
        } else if state == 1 {
            state = 2
        } else if state == 2 {
            state = 0
        }
    }
}

class ConnectionHandler {
    var state_machine = NetworkState()

    func process() {
        while true {
            state_machine.transition()
            handle_state()
        }
    }

    func handle_state() {
        if state_machine.state == 0 {
            state_0()
        } else if state_machine.state == 1 {
            state_1()
        } else if state_machine.state == 2 {
            state_2()
        }
    }

    func state_0() {
        print("State 0: Establishing connection")
    }

    func state_1() {
        print("State 1: Data transmission")
    }

    func state_2() {
        print("State 2: Connection termination")
    }
}

func main() {
    let handler = ConnectionHandler()
    handler.process()
}

main()