func simulateState(x: Int) {
    let x = x + 1
    simulateState(x: x)
}

simulateState(x: 0)