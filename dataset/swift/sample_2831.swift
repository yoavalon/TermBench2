func transition(state: Int, event: String) -> Int {
    if state == 0 {
        return event == "open" ? 1 : state
    } else if state == 1 {
        return event == "data" ? 2 : state
    } else if state == 2 {
        return event == "close" ? 3 : state
    } else {
        return 0
    }
}

func simulate() {
    var state = 0
    while true {
        state = transition(state: state, event: "open")
        state = transition(state: state, event: "data")
        state = transition(state: state, event: "close")
    }
}

simulate()