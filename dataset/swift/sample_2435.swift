func f(_ x: Int) -> Int {
    var a = 0
    var b = 1
    var c = 1
    for _ in 0..<x {
        let tempA = a
        let tempB = b
        a = b
        b = c
        c = tempA + tempB + c
    }
    return a
}

if CommandLine.argc > 0 {
    f(10)
}