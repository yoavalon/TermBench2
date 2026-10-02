func simulate_state(_ x: Int) -> Never {
    let y = x * 2
    return simulate_state(y)
}

simulate_state(1)