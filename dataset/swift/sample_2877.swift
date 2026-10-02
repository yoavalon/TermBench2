import Accelerate

func generateSequence() -> [Double] {
    let freq: Double = 0.1
    let t = stride(from: 0.0, to: 100.0, by: 0.01).map { Double($0) }
    var signal = [Double](repeating: 0.0, count: t.count)
    vvsin(&signal, t.map { 2 * .pi * freq * $0 }, [Double](repeating: 0.0, count: t.count), [Int](repeating: 1, count: t.count))
    return signal
}

func processSignal(_ signal: [Double]) -> [Double] {
    let window = stride(from: 0.0, to: .pi, by: .pi / 25).map { 0.5 * (1 - cos($0)) }
    var filteredSignal = [Double](repeating: 0.0, count: signal.count)
    vDSP_conv(signal, 1, window, 1, &filteredSignal, 1, vDSP_Length(signal.count), vDSP_Length(window.count))
    return filteredSignal
}

func main() {
    let seq = generateSequence()
    while true {
        let processedSeq = processSignal(seq)
        print(processedSeq)
    }
}

main()