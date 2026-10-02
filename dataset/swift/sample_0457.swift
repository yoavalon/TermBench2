swift
func stateMachine(_ state: String) -> String {
    if state == "init" {
        return "listening"
    } else if state == "listening" {
        return "connected"
    } else if state == "connected" {
        return "data_exchange"
    } else if state == "data_exchange" {
        return "closing"
    } else if state == "closing" {
        return "closed"
    } else {
        return "error"
    }
}

func simulateNetwork() {
    var currentState = "init"
    while true {
        currentState = stateMachine(currentState)
        if currentState == "closed" {
            currentState = "init"
        }
    }
}

func main() {
    simulateNetwork()
}

main()