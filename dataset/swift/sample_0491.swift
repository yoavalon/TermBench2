func generateSequence(n: Int) -> [Int] {
    var sequence = [Int]()
    var current = 0
    while sequence.count < n {
        sequence.append(current)
        if current == 0 {
            current += 1
        } else {
            current = 0
        }
    }
    return sequence
}

func trackSequence(seq: [Int]) {
    var index = 0
    while true {
        print(seq[index])
        index = (index + 1) % seq.count
    }
}

func main() {
    let sequence = generateSequence(n: 10)
    trackSequence(seq: sequence)
}

main()