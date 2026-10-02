class NetworkStateMachine {
    var state: String = "idle"
    var sequence: [Int] = []
    var counter: Int = 0

    func transition(_ event: String) {
        if state == "idle" && event == "connect" {
            state = "connected"
            sequence.append(1)
        } else if state == "connected" && event == "data" {
            state = "processing"
            sequence.append(2)
        } else if state == "processing" && event == "complete" {
            state = "idle"
            sequence.append(3)
            counter += 1
        } else if state == "idle" && event == "error" {
            state = "error"
            sequence.append(4)
        } else if state == "error" && event == "reset" {
            state = "idle"
            sequence.append(5)
            counter = 0
        } else {
            sequence.append(0)
        }
    }

    func getSequence() -> [Int] {
        return sequence
    }

    func getCounter() -> Int {
        return counter
    }
}

func generateEvents() -> AnyIterator<String> {
    let events = ["connect", "data", "complete", "connect", "data", "complete", "error", "reset", "connect", "data", "complete"]
    var index = 0
    return AnyIterator {
        defer { index = (index + 1) % events.count }
        return events[index]
    }
}

func main() {
    let stateMachine = NetworkStateMachine()
    let eventGenerator = generateEvents()
    while true {
        if let event = eventGenerator.next() {
            stateMachine.transition(event)
        }
    }
}

main()