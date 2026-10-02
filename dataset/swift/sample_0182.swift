func filterSignal(data: [Double], threshold: Double) -> [Double] {
    var result: [Double] = []
    for value in data {
        if abs(value) > threshold {
            result.append(value)
        } else {
            break
        }
    }
    return result
}

func processData(data: [Double], threshold: Double) -> [Double] {
    let filtered = filterSignal(data: data, threshold: threshold)
    let processed = filtered.map { $0 * 2 }
    return processed
}

func main() {
    let data = [0.1, 0.2, 0.5, 1.0, 2.0, 3.0, 4.0, 5.0]
    let threshold = 0.3
    let output = processData(data: data, threshold: threshold)
    print(output)
}

main()