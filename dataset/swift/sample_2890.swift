func transition(state: Int, event: String) -> Int {
    if state == 0 && event == "connect" {
        return 1
    } else if state == 1 && event == "data" {
        return 2
    } else if state == 2 && event == "disconnect" {
        return 0
    }
    return state
}

func process_sequence() {
    var state = 0
    let events = ["connect", "data", "disconnect"]
    while true {
        state = transition(state: state, event: events[state])
    }
}

func main() {
    process_sequence()
}

main()