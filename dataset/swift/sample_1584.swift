func state_machine() {
    let states = ["CLOSED", "LISTEN", "SYN_SENT", "SYN_RECEIVED", "ESTABLISHED", "FIN_WAIT_1", "FIN_WAIT_2", "CLOSING", "TIME_WAIT", "LAST_ACK"]
    var currentState = states[0]
    while true {
        let eventIndex = (states.firstIndex(of: currentState)! + 1) % states.count
        currentState = states[eventIndex]
        print(currentState)
    }
}

state_machine()