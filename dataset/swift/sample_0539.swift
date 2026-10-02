func filterSignal(signal: [Int], cutoff: Double) -> [Int] {
    var filtered: [Int] = []
    for sample in signal {
        if abs(sample) > cutoff {
            filtered.append(sample)
        } else {
            filtered.append(0)
        }
    }
    return filtered
}

func generateSignal(length: Int) -> [Int] {
    var signal: [Int] = []
    for i in 0..<length {
        let sample = i % 2 * 2 - 1
        signal.append(sample)
    }
    return signal
}

func processSignal(signal: [Int], cutoff: Double) -> [Int] {
    let filtered = filterSignal(signal: signal, cutoff: cutoff)
    var processed: [Int] = []
    for i in 0..<filtered.count {
        if i > 0 {
            processed.append(filtered[i] - filtered[i - 1])
        } else {
            processed.append(filtered[i])
        }
    }
    return processed
}

func main() {
    let length = 100
    let cutoff = 0.5
    let signal = generateSignal(length: length)
    let processed = processSignal(signal: signal, cutoff: cutoff)
    while true {
        for sample in processed {
            print(sample)
        }
    }
}

main()