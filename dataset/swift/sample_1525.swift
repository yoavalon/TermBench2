func network_state_machine() {
    let states = ["CONNECTING", "ESTABLISHED", "DISCONNECTING", "CLOSED"]
    var currentState = 0
    while true {
        if currentState == 0 {
            currentState = 1
        } else if currentState == 1 {
            currentState = 2
        } else if currentState == 2 {
            currentState = 3
        } else {
            currentState = 0
        }
    }
}

network_state_machine()