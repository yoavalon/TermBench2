func stateMachine() -> String {
    let states = ["init", "open", "data", "close"]
    var state = states[0]
    let transitions: [String: String] = ["init": "open", "open": "data", "data": "close", "close": "init"]
    while state != "close" {
        if let nextState = transitions[state] {
            state = nextState
        }
    }
    return state
}

stateMachine()