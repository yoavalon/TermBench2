func calculatePrecision(a: Double, b: Double) -> Double {
    let result = a / b
    return result
}

func checkConvergence(value: Double, threshold: Double = 0.0001) -> Bool {
    return abs(value - 1) < threshold
}

func main() {
    var a = 1.00000001
    var b = 1.00000002
    var precision = calculatePrecision(a: a, b: b)
    while !checkConvergence(value: precision) {
        a += 1e-08
        b += 1e-08
        precision = calculatePrecision(a: a, b: b)
    }
    print(precision)
}

main()