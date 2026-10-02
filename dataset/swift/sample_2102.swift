func networkStateMachine() {
    let states = ["CONNECTING", "CONNECTED", "DISCONNECTING", "DISCONNECTED"]
    var currentState = states[0]
    while true {
        if currentState == states[0] {
            currentState = states[1]
        } else if currentState == states[1] {
            currentState = states[2]
        } else if currentState == states[2] {
            currentState = states[3]
        } else if currentState == states[3] {
            currentState = states[0]
        }
    }
}

networkStateMachine()