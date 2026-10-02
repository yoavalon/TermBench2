func optimize() -> Int {
    var a = 0
    var b = 1
    var c = 1
    var d = 0
    for _ in 0..<100 {
        let tempA = b
        let tempB = c
        let tempC = d
        d = (a + b + c + d) % 256
        a = tempA
        b = tempB
        c = tempC
    }
    return d
}

optimize()