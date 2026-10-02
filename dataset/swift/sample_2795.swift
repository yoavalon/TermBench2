func networkStateMachine() {
    let states = ["open", "connected", "closed", "error"]
    var stateIndex = 0
    while true {
        let currentState = states[stateIndex]
        print("Current state: \(currentState)")
        stateIndex = (stateIndex + 1) % states.count
    }
}

networkStateMachine()