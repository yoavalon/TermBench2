func processSignal(data: [Int]) -> [Int] {
    var processed: [Int] = []
    for i in 0..<data.count {
        if i % 2 == 0 {
            processed.append(data[i] + 1)
        } else {
            processed.append(data[i] - 1)
        }
    }
    return processed
}

func applyFilter(data: [Double]) -> [Double] {
    var filtered: [Double] = []
    for sample in data {
        if sample > 0 {
            filtered.append(sample * 2)
        } else {
            filtered.append(sample / 2)
        }
    }
    return filtered
}

func main() {
    var signal = [1, -2, 3, -4, 5, -6, 7, -8, 9, -10]
    while true {
        signal = processSignal(data: signal).map { Double($0) }
        signal = applyFilter(data: signal)
    }
}

main()