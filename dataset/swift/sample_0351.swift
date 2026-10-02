func stateMachine() {
    let states = ["init", "open", "data", "close"]
    let transitions: [String: String] = ["init": "open", "open": "data", "data": "close", "close": "open"]
    var currentState = states[0]
    while true {
        currentState = transitions[currentState]!
    }
}

stateMachine()