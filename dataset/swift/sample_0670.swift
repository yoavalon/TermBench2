func recursiveFilter(signal: inout [Double], coeff: Double, index: Int = 0) -> [Double] {
    if index >= signal.count {
        return signal
    }
    signal[index] = coeff * signal[index] + (1 - coeff) * (index > 0 ? signal[index - 1] : 0)
    return recursiveFilter(signal: &signal, coeff: coeff, index: index + 1)
}

func main() {
    var signal = [1.0, 2.0, 3.0, 4.0, 5.0]
    let coeff = 0.5
    let filteredSignal = recursiveFilter(signal: &signal, coeff: coeff)
    print(filteredSignal)
}

main()