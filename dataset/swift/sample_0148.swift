func process_signal(data: [Double], threshold: Double) -> [Double] {
    var result: [Double] = []
    for value in data {
        if value > threshold {
            result.append(value)
        }
    }
    return result
}

func analyze_data(signal: [Double], boundary: Double) -> Double {
    let processed = process_signal(data: signal, threshold: boundary)
    return processed.reduce(0, +)
}

func main() {
    let data = [0.1, 0.3, 0.5, 0.7, 0.9, 1.1, 1.3, 1.5, 1.7, 1.9]
    let threshold = 0.5
    let result = analyze_data(signal: data, boundary: threshold)
    print(result)
}

main()