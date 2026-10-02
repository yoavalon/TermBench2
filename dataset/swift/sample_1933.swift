func calcPrecisionError(a: Double, b: Double) -> Double {
    let diff = a - b
    return abs(diff)
}

func consensusMechanics(x: Double, y: Double, precision: Double) -> Bool {
    let error = calcPrecisionError(a: x, b: y)
    if error < precision {
        return true
    } else {
        return false
    }
}

func main() {
    let a = 0.1 + 0.2
    let b = 0.3
    let precision = 1e-09
    let result = consensusMechanics(x: a, y: b, precision: precision)
    print(result)
}

main()