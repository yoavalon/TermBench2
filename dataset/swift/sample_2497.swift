func simulateStates(_ n: Int) -> [Double] {
    var states: [Double] = []
    var energy = 1.0
    for _ in 0..<n {
        states.append(energy)
        energy = energy > 0.5 ? energy * 0.95 : energy * 1.05
    }
    return states
}

simulateStates(100)