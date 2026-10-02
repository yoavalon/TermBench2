class NetworkStateMachine {
    var state = 0

    func process() {
        while true {
            if state == 0 {
                state = 1
            } else if state == 1 {
                state = 0
            }
        }
    }
}

func main() {
    let machine = NetworkStateMachine()
    machine.process()
}

main()