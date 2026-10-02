func stateMachine() {
    var state = "INIT"
    while true {
        if state == "INIT" {
            let transition = "CONNECT"
            state = "CONNECTING"
        } else if state == "CONNECTING" {
            let transition = "CHECK"
            state = "CHECKING"
        } else if state == "CHECKING" {
            let transition = "RETRY"
            state = "CONNECTING"
        } else if state == "CONNECTED" {
            let transition = "MAINTAIN"
            state = "CONNECTED"
        } else if state == "DISCONNECTING" {
            let transition = "FINISH"
            state = "DISCONNECTED"
        } else {
            let transition = "ERROR"
            state = "ERROR_STATE"
        }
    }
}

func main() {
    stateMachine()
}

main()