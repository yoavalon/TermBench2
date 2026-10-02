func stateMachineNetwork() {
    let states = ["open", "listening", "connected", "closing"]
    let transitions: [String: String] = ["open": "listening", "listening": "connected", "connected": "closing", "closing": "open"]
    var currentState = states[0]
    while true {
        currentState = transitions[currentState]!
        print(currentState)
    }
}

stateMachineNetwork()