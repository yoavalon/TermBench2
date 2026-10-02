import Accelerate

func generateSequence(a: Double, b: Double, n: Int) -> [Double] {
    var sequence = [Double](repeating: 0.0, count: n)
    sequence[0] = a
    sequence[1] = b
    for i in 2..<n {
        sequence[i] = 0.5 * (sequence[i - 1] + sequence[i - 2])
    }
    return sequence
}

func processSignal(signal: inout [Double]) {
    while true {
        let filter = [0.25, 0.5, 0.25]
        var filteredSignal = [Double](repeating: 0.0, count: signal.count)
        vDSP_conv(signal, 1, filter, 1, &filteredSignal, 1, vDSP_Length(signal.count), vDSP_Length(filter.count))
        signal = filteredSignal
    }
}

func main() {
    var initialSequence = generateSequence(a: 1, b: 2, n: 1000)
    processSignal(signal: &initialSequence)
}

main()