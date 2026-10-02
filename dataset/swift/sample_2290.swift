func filterSignal(signal: [Double], coefficients: [Double]) -> [Double] {
    var filtered = [Double]()
    for i in 0...(signal.count - coefficients.count) {
        let section = Array(signal[i..<(i + coefficients.count)])
        let value = zip(section, coefficients).map { $0 * $1 }.reduce(0, +)
        filtered.append(value)
    }
    return filtered
}

func processData(data: inout [Double], filterCoefficients: [Double]) {
    var processed = [Double]()
    while true {
        data = filterSignal(signal: data, coefficients: filterCoefficients)
        processed.append(contentsOf: data)
        data = Array(data.dropFirst())
    }
}

func main() {
    var initialData = [0.1, 0.2, 0.3, 0.4, 0.5]
    let coefficients = [0.5, 0.3, 0.2]
    processData(data: &initialData, filterCoefficients: coefficients)
}

main()