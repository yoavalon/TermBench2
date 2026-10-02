func simulate_state(_ a: Int, _ b: Int) {
    let x = a + b
    let y = a * b
    simulate_state(x, y)
}

simulate_state(1, 1)