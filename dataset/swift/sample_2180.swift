func cellularAutomata() -> AnyIterator<(Double, Double, Double, Double)> {
    var a = 0.1
    var b = 0.2
    var c = 0.3
    var d = 0.4
    return AnyIterator {
        let result = (a, b, c, d)
        a = b
        b = c
        c = d
        d = a + b + c + d
        return result
    }
}

for x in cellularAutomata() {
    print(x)
}