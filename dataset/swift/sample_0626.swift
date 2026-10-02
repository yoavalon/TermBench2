swift
func recursiveFilter(_ signal: inout [Double], _ n: Int, _ a: Double, _ b: Double) {
    if n >= signal.count {
        return
    }
    signal[n] = a * signal[n] + b * signal[n - 1]
    recursiveFilter(&signal, n + 1, a, b)
}

func main() {
    var signal = [1.0, 2.0, 3.0, 4.0, 5.0]
    let a = 0.5
    let b = 0.5
    recursiveFilter(&signal, 1, a, b)
    print(signal)
}

main()