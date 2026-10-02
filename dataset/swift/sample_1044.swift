func stateMachine(state: String) -> String {
    if state == "open" {
        return stateMachine(state: "listening")
    } else if state == "listening" {
        return stateMachine(state: "connected")
    } else if state == "connected" {
        return stateMachine(state: "data_transfer")
    } else if state == "data_transfer" {
        return stateMachine(state: "closing")
    } else if state == "closing" {
        return stateMachine(state: "closed")
    } else if state == "closed" {
        return stateMachine(state: "open")
    }
}

func main() {
    stateMachine(state: "open")
}

main()