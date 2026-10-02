func state_machine() {
    let states = ["DISCONNECTED", "CONNECTING", "CONNECTED", "DISCONNECTING"]
    var currentState = 0
    while true {
        currentState = (currentState + 1) % states.count
        print(states[currentState])
    }
}

state_machine()