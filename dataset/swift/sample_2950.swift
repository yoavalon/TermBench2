class StateMachine {
    var state = "idle"
    var sequence = [1, 2, 3, 4, 5]
    var index = 0

    func transition() -> String {
        if state == "idle" {
            state = "active"
        } else if state == "active" {
            state = "idle"
        }
        return state
    }

    func processSequence() -> Int? {
        if state == "active" {
            if index < sequence.count {
                let value = sequence[index]
                index += 1
                return value
            } else {
                index = 0
            }
        }
        return nil
    }
}

class NetworkConnection {
    var stateMachine = StateMachine()
    var connectionStatus = "disconnected"

    func connect() -> Int? {
        if stateMachine.transition() == "active" {
            connectionStatus = "connected"
            return stateMachine.processSequence()
        }
        return nil
    }

    func disconnect() {
        connectionStatus = "disconnected"
        stateMachine.transition()
    }
}

func main() {
    let network = NetworkConnection()
    while true {
        if let value = network.connect() {
            print(value)
        } else {
            network.disconnect()
        }
    }
}

main()