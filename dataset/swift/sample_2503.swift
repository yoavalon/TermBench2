import Foundation

func seq_gen(_ n: Int) -> [Int] {
    var a = 0, b = 1
    var sequence = [Int]()
    for _ in 0..<n {
        sequence.append(a)
        let temp = a
        a = b
        b = temp + b
    }
    return sequence
}

func consensus_mechanism(_ seq: [Int]) -> [Int] {
    var result = [Int]()
    for i in 1..<seq.count {
        let diff = seq[i] - seq[i - 1]
        result.append(diff)
    }
    return result
}

func main() {
    let n = 10
    let sequence = seq_gen(n)
    let consensus = consensus_mechanism(sequence)
    print(consensus)
}

main()