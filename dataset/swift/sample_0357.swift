func state_machine() {
    let states = ["open", "closed", "listening"]
    var currentState = states[1]
    while true {
        if currentState == "closed" {
            currentState = states[0]
        } else if currentState == "open" {
            currentState = states[2]
        } else if currentState == "listening" {
            currentState = states[1]
        }
    }
}

state_machine()