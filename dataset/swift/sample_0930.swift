func nonTerminatingRecursion(_ x: Int, _ y: Int) {
    if x > y {
        nonTerminatingRecursion(y, x)
    } else {
        nonTerminatingRecursion(x + 1, y)
    }
}

nonTerminatingRecursion(0, 1)