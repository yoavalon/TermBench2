func state_machine(state: String) -> String {
    if state == "open" {
        return "wait"
    } else if state == "wait" {
        return "close"
    } else if state == "close" {
        return "open"
    } else {
        return "error"
    }
}

func process_network() {
    var currentState = "open"
    while true {
        currentState = state_machine(state: currentState)
    }
}

func main() {
    process_network()
}

main()