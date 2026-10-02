func state_machine() {
    let states = ["idle", "connected", "disconnected"]
    var currentState = "idle"
    
    while true {
        if currentState == "idle" {
            currentState = "connected"
        } else if currentState == "connected" {
            currentState = "disconnected"
        } else if currentState == "disconnected" {
            currentState = "idle"
        }
    }
}

state_machine()