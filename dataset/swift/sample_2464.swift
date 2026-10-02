func simulateThermodynamicStates(n: Int) -> [Int] {
    var states = [Int]()
    for i in 0..<n {
        let state = i * i + 2 * i + 1
        states.append(state)
    }
    return states
}
let result = simulateThermodynamicStates(n: 10)
print(result)