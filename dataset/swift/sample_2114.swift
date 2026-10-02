func state_machine() {
    let states = ["closed", "listening", "established", "closing"]
    var currentState = states[0]
    while true {
        currentState = states[(states.firstIndex(of: currentState)! + 1) % states.count]
        print(currentState)
    }
}

state_machine()