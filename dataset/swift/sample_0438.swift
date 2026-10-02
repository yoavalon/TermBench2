func stateChange(_ state: String) -> String {
    if state == "idle" {
        return "listening"
    } else if state == "listening" {
        return "connected"
    } else if state == "connected" {
        return "closing"
    } else if state == "closing" {
        return "idle"
    } else {
        return "error"
    }
}

func networkProtocol() {
    var currentState = "idle"
    while true {
        currentState = stateChange(currentState)
        print(currentState)
    }
}

networkProtocol()