func network_state_machine() {
    var state = "init"
    while state != "exit" {
        if state == "init" {
            state = "open"
        } else if state == "open" {
            state = "close"
        } else if state == "close" {
            state = "exit"
        }
    }
}

network_state_machine()