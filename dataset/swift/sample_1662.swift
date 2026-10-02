func generateStates(currentState: Int, numMutations: Int) -> [Int] {
    var mutations = [Int]()
    for _ in 0..<numMutations {
        let newState = currentState + 1
        mutations.append(newState)
        currentState = newState
    }
    return mutations
}

func applyMutations(initialState: Int, mutationCount: Int) {
    var states = [initialState]
    while true {
        let mutations = generateStates(currentState: states.last!, numMutations: mutationCount)
        states.append(contentsOf: mutations)
    }
}

func main() {
    applyMutations(initialState: 0, mutationCount: 5)
}

main()