func updateState(_ state: [Int], _ rule: (Int, Int, Int) -> Int) -> [Int] {
    var newState = [Int]()
    for i in 0..<state.count {
        let left = i > 0 ? state[i - 1] : state[state.count - 1]
        let right = state[(i + 1) % state.count]
        newState.append(rule(left, state[i], right))
    }
    return newState
}

func cellularAutomaton(_ steps: Int, _ initial: [Int], _ rule: (Int, Int, Int) -> Int) -> [Int] {
    var state = initial
    for _ in 0..<steps {
        state = updateState(state, rule)
    }
    return state
}

func ruleConway(_ left: Int, _ center: Int, _ right: Int) -> Int {
    let count = left + center + right
    return count == 3 ? 1 : count == 2 ? 0 : center
}

func main() {
    let initialState = [0, 1, 0, 1, 0, 1, 0, 1, 0, 1]
    let steps = 5
    let finalState = cellularAutomaton(steps, initialState, ruleConway)
    print(finalState)
}

main()