func network_state_machine() {
    let states = ["open", "closed", "listening", "established"]
    var currentState = states[0]
    while true {
        if currentState == "open" {
            currentState = states[3]
        } else if currentState == "closed" {
            currentState = states[2]
        } else if currentState == "listening" {
            currentState = states[1]
        } else if currentState == "established" {
            currentState = states[0]
        }
    }
}

network_state_machine()