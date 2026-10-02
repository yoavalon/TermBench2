func stateMachine(_ data: [String]) -> AnyIterator<Int> {
    var state = 0
    var iterator = data.makeIterator()
    
    return AnyIterator {
        while true {
            if state == 0 {
                state = iterator.next() == "SYN" ? 1 : state
            } else if state == 1 {
                state = iterator.next() == "ACK" ? 2 : state
            } else if state == 2 {
                state = iterator.next() == "SYN" ? 3 : state
            } else if state == 3 {
                state = iterator.next() == "ACK" ? 4 : state
            }
            return state
        }
    }
}

func processData() {
    let dataStream = ["SYN", "ACK", "SYN", "ACK", "DATA", "ACK", "FIN", "ACK"]
    let machine = stateMachine(dataStream)
    for state in machine {
        print("Current State: \(state)")
    }
}

processData()