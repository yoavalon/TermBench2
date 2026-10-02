func simulate_state(_ a: Int, _ b: Int) -> Int {
    if a == b {
        return a
    }
    if a < b {
        return simulate_state(a + 1, b)
    }
    return simulate_state(a - 1, b)
}

simulate_state(0, 5)