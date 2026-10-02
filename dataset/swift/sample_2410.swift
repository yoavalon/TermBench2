func simulate_state(_ n: Int) -> Int {
    var a = 0
    var b = 1
    for _ in 0..<n {
        let temp = b
        b = a + b
        a = temp
    }
    return a
}

simulate_state(10)