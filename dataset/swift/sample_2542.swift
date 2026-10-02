func generate_sequence(n: Int) -> [Int] {
    var seq: [Int] = []
    for i in 0..<n {
        seq.append(i * i + 2 * i + 1)
    }
    return seq
}

func filter_sequence(seq: [Int], threshold: Int) -> [Int] {
    var filtered: [Int] = []
    for item in seq {
        if item > threshold {
            filtered.append(item)
        }
    }
    return filtered
}

func main() {
    let n = 10
    let threshold = 15
    let seq = generate_sequence(n: n)
    let result = filter_sequence(seq: seq, threshold: threshold)
    print(result)
}

main()