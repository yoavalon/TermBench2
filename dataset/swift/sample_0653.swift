func state_machine(state: Int, connections: inout [Int]) -> Int {
    if connections.isEmpty {
        return state
    }
    let nextState = state ^ connections.removeLast()
    return state_machine(state: nextState, connections: &connections)
}

func main() {
    var initial_state = 5
    var connections = [1, 2, 4]
    let final_state = state_machine(state: initial_state, connections: &connections)
    print(final_state)
}

main()