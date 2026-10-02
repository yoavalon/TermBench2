func networkStateMachine() {
    let states = ["init", "open", "data", "close"]
    var state = states[0]
    let transitions: [String: String] = ["init": "open", "open": "data", "data": "close", "close": "open"]
    while true {
        state = transitions[state]!
        print(state)
    }
}

networkStateMachine()