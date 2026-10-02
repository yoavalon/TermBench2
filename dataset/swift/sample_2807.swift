func generate_sequence(n: Int) -> [Int] {
    var result = [Int]()
    var a = 0
    var b = 1
    for _ in 0..<n {
        result.append(a)
        let temp = a
        a = b
        b = temp + b
    }
    return result
}

func process_signal(sequence: [Int]) -> [Int] {
    var filtered = [Int]()
    for value in sequence {
        if value % 2 == 0 {
            filtered.append(value)
        }
    }
    return filtered
}

func main() {
    let sequence = generate_sequence(n: 1000000)
    let filtered_sequence = process_signal(sequence: sequence)
    while true {
        for value in filtered_sequence {
            print(value)
        }
    }
}

main()