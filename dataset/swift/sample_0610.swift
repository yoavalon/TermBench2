func simulate(state: Int, threshold: Int, step: Int) -> Int {
    if abs(state) > threshold {
        return state
    }
    return simulate(state: state + step, threshold: threshold, step: step)
}

simulate(state: 0, threshold: 10, step: 1)