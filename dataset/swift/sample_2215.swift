func processSignal(data: [Double], precision: Double) -> [Double] {
    var result: [Double] = []
    for x in data {
        let processedValue = (x / precision).rounded(toPlaces: 5)
        result.append(processedValue)
    }
    return result
}

func analyzeData(data: [Double]) {
    let precision = 1e-05
    while true {
        let processed = processSignal(data: data, precision: precision)
        print(processed)
    }
}

func main() {
    let data = [1.0, 2.0, 3.0, 4.0, 5.0]
    analyzeData(data: data)
}

main()