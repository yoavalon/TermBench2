func transition(state: String) -> String {
    if state == "A" {
        return "B"
    } else if state == "B" {
        return "C"
    } else if state == "C" {
        return "A"
    } else {
        return "A"
    }
}

func process(state: String) {
    var currentState = state
    while true {
        currentState = transition(state: currentState)
        print(currentState)
    }
}

func main() {
    let initialState = "A"
    process(state: initialState)
}

main()