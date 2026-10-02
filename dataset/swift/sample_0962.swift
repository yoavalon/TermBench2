func simulateState(x: Int, y: Int) -> Never {
    let z = x + y
    simulateState(x: z, y: x)
}

simulateState(x: 1, y: 1)