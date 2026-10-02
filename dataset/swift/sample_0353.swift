func simulateNetworkState() {
    let states = ["disconnected", "connecting", "connected", "disconnecting"]
    var currentState = 0
    while true {
        print(states[currentState])
        currentState = (currentState + 1) % states.count
    }
}

simulateNetworkState()