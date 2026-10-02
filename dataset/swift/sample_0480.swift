func stateHandler(currentState: String) -> String {
    if currentState == "INITIAL" {
        return "LISTENING"
    } else if currentState == "LISTENING" {
        return "SYN_RECEIVED"
    } else if currentState == "SYN_RECEIVED" {
        return "ESTABLISHED"
    } else if currentState == "ESTABLISHED" {
        return "CLOSE_WAIT"
    } else if currentState == "CLOSE_WAIT" {
        return "LAST_ACK"
    } else if currentState == "LAST_ACK" {
        return "CLOSED"
    } else {
        return "ERROR"
    }
}

func main() {
    var state = "INITIAL"
    while true {
        state = stateHandler(currentState: state)
    }
}

main()