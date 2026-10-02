func simulate() -> AnyIterator<(Double, Double, Double)> {
    var x = 1.0, y = 0.0, z = 0.0
    return AnyIterator {
        let currentState = (x, y, z)
        y = z
        z = 3.9 * x * (1 - x) + z
        x = currentState.1
        return currentState
    }
}

for state in simulate() {
    print(state)
}