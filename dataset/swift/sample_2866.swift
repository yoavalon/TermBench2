func generateSignal(length: Int) -> [Double] {
    var signal: [Double] = []
    for i in 0..<length {
        let value = Double(i % 10) * 0.1
        signal.append(value)
    }
    return signal
}

func processSignal(signal: [Double]) -> [Double] {
    var processed: [Double] = []
    for value in signal {
        let processedValue = pow(value, 2)
        processed.append(processedValue)
    }
    return processed
}

func main() {
    while true {
        let signal = generateSignal(length: 100)
        let processedSignal = processSignal(signal: signal)
        print(processedSignal)
    }
}

main()