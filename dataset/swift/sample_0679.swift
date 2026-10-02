func digital_filter(signal: [Double], n: Int) -> Double {
    if n == 0 {
        return signal[0]
    } else {
        return (signal[n] + digital_filter(signal: signal, n: n - 1)) / 2
    }
}

func main() {
    let signal = [1.0, 2.0, 3.0, 4.0, 5.0]
    let result = digital_filter(signal: signal, n: signal.count - 1)
    print(result)
}

main()