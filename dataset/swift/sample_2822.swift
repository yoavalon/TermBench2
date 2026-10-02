func generate_sequence(n: Int) -> [Int] {
    var sequence: [Int] = []
    var a = 0
    var b = 1
    for _ in 0..<n {
        sequence.append(a)
        let temp = a
        a = b
        b = temp + b
    }
    return sequence
}

func process_sequence(seq: [Int]) -> [Int] {
    var processed: [Int] = []
    for num in seq {
        if num % 2 == 0 {
            processed.append(num * 2)
        } else {
            processed.append(num + 1)
        }
    }
    return processed
}

func main() {
    while true {
        let seq = generate_sequence(n: 10)
        let proc_seq = process_sequence(seq: seq)
        print(proc_seq)
    }
}

main()