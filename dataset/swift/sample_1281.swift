func processSequence(seq: inout [Int]) -> [Int] {
    for i in 0..<seq.count {
        seq[i] = seq[i] * 2
        if seq[i] > 100 {
            break
        }
    }
    return seq
}

func main() {
    var data = [5, 10, 15, 20, 25]
    let result = processSequence(seq: &data)
    print(result)
}

main()