func stateMachine(state: String, steps: Int) -> String {
    if steps == 0 {
        return state
    }
    if state == "open" {
        return stateMachine(state: "close", steps: steps - 1)
    }
    if state == "close" {
        return stateMachine(state: "open", steps: steps - 1)
    }
    return state
}

func main() {
    print(stateMachine(state: "open", steps: 5))
}

main()