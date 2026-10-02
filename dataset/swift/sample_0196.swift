func applyFilter(data: [Double], filterCoefficients: [Double]) -> [Double] {
    var filteredData: [Double] = []
    for i in 0..<data.count {
        var sample: Double = 0
        for j in 0..<filterCoefficients.count {
            if i - j >= 0 {
                sample += data[i - j] * filterCoefficients[j]
            }
        }
        filteredData.append(sample)
    }
    return filteredData
}

func processSignal(data: [Double]) -> [Double] {
    let coefficients: [Double] = [0.25, 0.5, 0.25]
    return applyFilter(data: data, filterCoefficients: coefficients)
}

func main() {
    let signal: [Double] = [1, 2, 3, 4, 5]
    let processedSignal = processSignal(data: signal)
    for value in processedSignal {
        print(value)
    }
}

main()