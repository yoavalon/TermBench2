func generate_sequence(n: Int, a0: Int, r: Int) -> [Int] {
    var seq = [a0]
    for i in 1..<n {
        let next_value = seq.last! * r
        seq.append(next_value)
    }
    return seq
}

func filter_sequence(seq: [Int], threshold: Int) -> [Int] {
    var filtered = [Int]()
    for value in seq {
        if abs(value) > threshold {
            filtered.append(value)
        }
    }
    return filtered
}

func analyze_signal(seq: [Int], window_size: Int) -> [Double] {
    var analysis = [Double]()
    for i in 0..<(seq.count - window_size + 1) {
        let window = Array(seq[i..<(i + window_size)])
        let avg = Double(window.reduce(0, +)) / Double(window_size)
        analysis.append(avg)
    }
    return analysis
}

func main() {
    let n = 10
    let a0 = 1
    let r = 2
    let threshold = 10
    let window_size = 3
    let sequence = generate_sequence(n: n, a0: a0, r: r)
    let filtered_sequence = filter_sequence(seq: sequence, threshold: threshold)
    let signal_analysis = analyze_signal(seq: filtered_sequence, window_size: window_size)
    print(sequence)
    print(filtered_sequence)
    print(signal_analysis)
}

main()