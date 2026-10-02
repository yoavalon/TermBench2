func process_signal(data: [Double], factor: Double) -> [Double] {
    let result = data.map { $0 * factor }
    return result.map { round($0 * 100000) / 100000 }
}

func main() {
    let signal = [0.123456789, 0.23456789, 0.345678901]
    let factor = 1.23456
    let processed = process_signal(data: signal, factor: factor)
    print(processed)
}

main()