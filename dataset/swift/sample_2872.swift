class StateMachine {
    var state = 0

    func transition() {
        if state == 0 {
            state = 1
        } else if state == 1 {
            state = 2
        } else if state == 2 {
            state = 0
        }
    }
}

func main() {
    let sm = StateMachine()
    while true {
        sm.transition()
        print(sm.state)
    }
}

main()