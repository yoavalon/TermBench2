func simulatePressure(a: Double, b: Double, c: Double) -> Double {
    return (a + b + c) / 3.0
}

func calculateTemperature(pressure: Double, constant: Double) -> Double {
    return pressure * constant
}

func analyzeSystem(a: Double, b: Double, c: Double, constant: Double) -> Double {
    let pressure = simulatePressure(a: a, b: b, c: c)
    let temperature = calculateTemperature(pressure: pressure, constant: constant)
    return temperature
}

func main() {
    let a = 100.0
    let b = 200.0
    let c = 150.0
    let constant = 0.5
    let result = analyzeSystem(a: a, b: b, c: c, constant: constant)
    print(result)
}

main()