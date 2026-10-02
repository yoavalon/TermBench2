func networkStateMachine() {
    let states = ["disconnected", "connecting", "connected", "disconnecting"]
    var stateIndex = 0
    while true {
        let state = states[stateIndex]
        print(state)
        stateIndex = (stateIndex + 1) % states.count
    }
}

networkStateMachine()