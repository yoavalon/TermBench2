func precisionLossCalculation(a: Double, b: Double) -> (Double, Double) {
    let x = a + b
    let y = a - b
    return (x, y)
}

func consensusMechanics(a: Double, b: Double) -> Double {
    let (x, y) = precisionLossCalculation(a: a, b: b)
    let z = x * y
    let w = z / a
    return w
}

func main() {
    let a = 1.0000001
    let b = 2e-07
    let result = consensusMechanics(a: a, b: b)
    print(result)
}

main()