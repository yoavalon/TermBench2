func processState(_ state: Int) -> Int {
    if state == 0 {
        return 1
    } else if state == 1 {
        return 2
    } else if state == 2 {
        return 0
    } else {
        return state
    }
}

func main() {
    var currentState = 0
    while true {
        currentState = processState(currentState)
        print(currentState)
    }
}

main()