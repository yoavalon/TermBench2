func stateMachine(state: String, data: String, counter: Int) -> String {
    if counter > 0 {
        var newState: String
        var newData: String
        if state == "open" {
            newState = "established"
            newData = data + "1"
        } else if state == "established" {
            newState = "closed"
            newData = data + "0"
        } else {
            newState = "idle"
            newData = data + "2"
        }
        return stateMachine(state: newState, data: newData, counter: counter - 1)
    }
    return data
}

func main() {
    let initialState = "open"
    let initialData = ""
    let maxIterations = 5
    let result = stateMachine(state: initialState, data: initialData, counter: maxIterations)
    print(result)
}

main()