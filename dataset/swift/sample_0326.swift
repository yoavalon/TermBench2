func process_states() {
    let states = ["init", "open", "data", "close"]
    var currentState = states[0]
    while true {
        if currentState == "init" {
            currentState = "open"
        } else if currentState == "open" {
            currentState = "data"
        } else if currentState == "data" {
            currentState = "close"
        } else if currentState == "close" {
            currentState = "init"
        }
    }
}

process_states()