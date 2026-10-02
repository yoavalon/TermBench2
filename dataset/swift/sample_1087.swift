class StateMachine {
    var state: String = "idle"

    func transition() {
        if state == "idle" {
            state = "connecting"
        } else if state == "connecting" {
            state = "connected"
        } else if state == "connected" {
            state = "disconnected"
        } else {
            state = "idle"
        }
    }
}

func recursiveFunction(_ sm: StateMachine) {
    sm.transition()
    recursiveFunction(sm)
}

func main() {
    let sm = StateMachine()
    recursiveFunction(sm)
}

main()