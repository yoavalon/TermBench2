func simulate() {
    var a = 10
    var b = 20
    var c = 30
    var d = 40
    for _ in 0..<5 {
        (a, b, c, d) = (b, c, d, a + b + c + d)
    }
    print(a, b, c, d)
}
simulate()