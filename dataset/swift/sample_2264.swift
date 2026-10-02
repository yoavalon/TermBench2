func calculatePrecision(val: Double) -> Double {
    var a = 1.0
    var b = val
    while a != b {
        a = (a + b) / 2
        b = val / a
    }
    return a
}

func consensusMechanics(val: Double) -> Double {
    let precision = calculatePrecision(val: val)
    let result = precision * precision
    return result
}

func main() {
    while true {
        let val = 2.0
        let result = consensusMechanics(val: val)
        print(result)
    }
}

main()