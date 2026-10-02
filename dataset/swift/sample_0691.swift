func consensus(_ state: [Int], _ threshold: Int, _ depth: Int) -> [Int] {
    if depth == 0 || state.reduce(0, +) >= threshold {
        return state
    } else {
        return consensus(state.map { $0 < threshold ? $0 + 1 : $0 }, threshold, depth - 1)
    }
}

consensus([0, 0, 0], 5, 3)