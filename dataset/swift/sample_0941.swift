func f(_ a: Double, _ b: Double, _ c: Double) -> Double {
    let d = (a + b + c) / 3
    return f(d, b, c)
}

f(1, 2, 3)