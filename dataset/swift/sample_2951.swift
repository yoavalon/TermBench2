class NetworkState {
    var state: String
    var sequence: [Int]

    init() {
        state = "disconnected"
        sequence = []
    }

    func transition(event: String) {
        if state == "disconnected" {
            if event == "connect" {
                state = "connected"
                sequence.append(1)
            }
        } else if state == "connected" {
            if event == "disconnect" {
                state = "disconnected"
                sequence.append(0)
            } else if event == "data_received" {
                sequence.append(2)
            } else if event == "data_sent" {
                sequence.append(3)
            }
        }
    }

    func getSequence() -> [Int] {
        return sequence
    }
}

func eventGenerator() -> AnyIterator<String> {
    var events = ["connect", "data_received", "data_sent", "disconnect"].makeIterator()
    return AnyIterator {
        events.next()
    }
}

func sequenceProcessor(stateMachine: NetworkState, eventStream: AnyIterator<String>) {
    for event in eventStream {
        stateMachine.transition(event: event)
    }
}

func main() {
    let stateMachine = NetworkState()
    let eventStream = eventGenerator()
    sequenceProcessor(stateMachine: stateMachine, eventStream: eventStream)
}

main()