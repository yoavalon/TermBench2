func filterSignal(signal: [Double], threshold: Double) -> [Double] {
    if signal.isEmpty {
        return []
    } else {
        let head = signal[0]
        let tail = Array(signal.dropFirst())
        if abs(head) > threshold {
            return [head] + filterSignal(signal: tail, threshold: threshold)
        } else {
            return filterSignal(signal: tail, threshold: threshold)
        }
    }
}

func main() {
    let signal = [0.1, -0.3, 0.5, -0.2, 0.8, 0.4, -0.6, 0.7]
    let threshold = 0.5
    let result = filterSignal(signal: signal, threshold: threshold)
    print(result)
}

main()