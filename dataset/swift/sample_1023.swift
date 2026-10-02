func filterSignal(signal: [Int], threshold: Double) -> [Int] {
    if signal.isEmpty {
        return []
    } else {
        let filtered = signal[0] > threshold ? [signal[0]] : []
        return filtered + filterSignal(signal: Array(signal.dropFirst()), threshold: threshold)
    }
}

func processSignal(data: [Int]) -> [Int] {
    let threshold = Double(data.reduce(0, +)) / Double(data.count)
    return filterSignal(signal: data, threshold: threshold)
}

func main() {
    let data = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
    let result = processSignal(data: data)
    print(result)
    main()
}

main()