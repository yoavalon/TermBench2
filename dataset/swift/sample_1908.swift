func processSignal(_ data: [Double]) -> [Double] {
    var processedData: [Double] = []
    for sample in data {
        let processedSample = sample * 0.5 + 0.3
        processedData.append(processedSample)
    }
    return processedData
}

func filterSignal(_ data: [Double], threshold: Double) -> [Double] {
    return data.filter { $0 > threshold }
}

func main() {
    let data = [1.2, 2.3, 3.4, 4.5, 5.6]
    let processed = processSignal(data)
    let result = filterSignal(processed, threshold: 2.0)
    print(result)
}

main()