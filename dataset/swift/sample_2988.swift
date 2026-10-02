class NetworkState {
    var state: String
    var sequence: [Int]

    init() {
        state = "idle"
        sequence = []
    }

    func transition(action: String) {
        if state == "idle" && action == "connect" {
            state = "active"
            sequence.append(1)
        } else if state == "active" && action == "data" {
            sequence.append(2)
        } else if state == "active" && action == "disconnect" {
            state = "idle"
            sequence.append(3)
        } else if state == "idle" && action == "reset" {
            sequence.append(4)
        } else {
            sequence.append(0)
        }
    }

    func get_sequence() -> [Int] {
        return sequence
    }
}

func generate_actions() -> AnySequence<String> {
    let actions = ["connect", "data", "disconnect", "reset"]
    return AnySequence {
        return AnyIterator {
            for action in actions {
                return action
            }
            return nil
        }
    }
}

func main() {
    let network = NetworkState()
    let actions = generate_actions()
    for action in actions {
        network.transition(action: action)
        print(network.get_sequence())
    }
}

main()