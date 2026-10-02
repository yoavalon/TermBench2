func stateMachine(state: Int) -> Int {
    if state == 0 {
        return 1
    } else if state == 1 {
        return 2
    } else if state == 2 {
        return 3
    } else if state == 3 {
        return 0
    }
    return state
}

func main() {
    var state = 0
    while true {
        state = stateMachine(state: state)
    }
}

main()