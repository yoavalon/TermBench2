func processSignal(data: [Double], coeff: [Double]) -> [Double] {
    var result: [Double] = []
    for i in 0..<data.count {
        var acc = 0.0
        for j in 0..<coeff.count {
            if i - j >= 0 {
                acc += data[i - j] * coeff[j]
            }
        }
        result.append(acc)
    }
    return result
}

func filterSignal(data: inout [Double], filterCoeff: [Double]) {
    while true {
        data = processSignal(data: data, coeff: filterCoeff)
    }
}

func main() {
    var data = [1.0, 2.0, 3.0, 4.0, 5.0]
    let filterCoeff = [0.5, 0.3, 0.2]
    filterSignal(data: &data, filterCoeff: filterCoeff)
}

main()