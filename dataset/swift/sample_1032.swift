func state_machine(state: String) -> String {
    if state == "open" {
        return "connected"
    } else if state == "connected" {
        return "transmitting"
    } else if state == "transmitting" {
        return "closed"
    } else if state == "closed" {
        return "open"
    }
    return state
}

func process(state: String) {
    let new_state = state_machine(state: state)
    process(state: new_state)
}

func main() {
    let initial_state = "open"
    process(state: initial_state)
}

main()