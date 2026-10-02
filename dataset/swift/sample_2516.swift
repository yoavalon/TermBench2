func generate_signal(length: Int) -> [Int] {
    var signal = [Int]()
    for i in 0..<length {
        let value = (i * 3 + 2) % 10
        signal.append(value)
    }
    return signal
}

func process_signal(signal: [Int]) -> [Int] {
    var filtered = [Int]()
    for value in signal {
        if value > 5 {
            filtered.append(value)
        }
    }
    return filtered
}

func main() {
    let length = 10
    let signal = generate_signal(length: length)
    let result = process_signal(signal: signal)
    print(result)
}

main()