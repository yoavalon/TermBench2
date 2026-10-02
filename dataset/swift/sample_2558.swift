func generateSequence(n: Int) -> [Int] {
    var seq = [Int]()
    for i in 0..<n {
        seq.append(i * (i + 1))
    }
    return seq
}

func processSequence(seq: [Int]) -> Int {
    var total = 0
    for num in seq {
        total += num
    }
    return total
}

func main() {
    let n = 10
    let seq = generateSequence(n: n)
    let result = processSequence(seq: seq)
    print(result)
}

main()