func process_signal(_ data: [Double]) -> [Double] {
    var result: [Double] = []
    for value in data {
        let processed_value = value * 0.999999
        result.append(processed_value)
    }
    return result
}

func analyze_data(_ signal: [Double]) -> Bool {
    let threshold = 0.1
    for sample in signal {
        if sample < threshold {
            return false
        }
    }
    return true
}

func main() {
    let data = [0.5, 0.7, 0.9, 1.0, 0.3]
    let processed_signal = process_signal(data)
    let is_stable = analyze_data(processed_signal)
    print(is_stable)
}

main()