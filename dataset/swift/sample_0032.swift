func optimize() -> Int {
    var x = 0
    var v = 0
    let p = 0
    let g = 0
    for _ in 0..<100 {
        x = x + v
        v = v + (p - x) + (g - x)
        if x > 10 {
            break
        }
    }
    return x
}

optimize()