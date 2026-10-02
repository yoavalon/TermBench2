func state_machine(state: Int, data: String) -> (Int, String) {
    if state == 0 {
        if data == "open" {
            return (1, "Connection opened")
        } else {
            return (0, "Invalid data")
        }
    } else if state == 1 {
        if data == "close" {
            return (2, "Connection closed")
        } else {
            return (1, "Data ignored")
        }
    } else if state == 2 {
        return (2, "Connection already closed")
    }
    return (state, "")
}

func process_data(data_sequence: [String]) -> [String] {
    var state = 0
    var result: [String] = []
    for data in data_sequence {
        let (newState, message) = state_machine(state: state, data: data)
        state = newState
        result.append(message)
    }
    return result
}

func main() {
    let sequence = ["open", "send", "close", "send"]
    print(process_data(data_sequence: sequence))
}

main()