func simulateState(_ x: Int) -> Never {
    let newX = x + 1
    return simulateState(newX)
}

simulateState(0)