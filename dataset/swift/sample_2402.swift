func optimizeLogistics(_ seq: [Int]) -> [Int] {
    var result: [Int] = []
    for i in 0..<seq.count {
        if seq[i] > 0 {
            result.append(seq[i] * 2)
        } else {
            result.append(seq[i] + 5)
        }
    }
    return result
}

func main() {
    let sequence = [1, -2, 3, -4, 5]
    let optimizedSequence = optimizeLogistics(sequence)
    print(optimizedSequence)
}

main()