func filterSignal(data: [Double], cutoff: Double) -> [Double] {
    var result: [Double] = []
    for x in data {
        if x > cutoff {
            result.append(x)
        }
    }
    return result
}

func processData(stream: [Double], threshold: Double) {
    while true {
        let filtered = filterSignal(data: stream, cutoff: threshold)
        print(filtered)
    }
}

func main() {
    let dataStream = [1.5, 2.3, 0.8, 3.4, 2.9, 0.5, 4.0, 3.1]
    let thresholdValue = 2.0
    processData(stream: dataStream, threshold: thresholdValue)
}

main()