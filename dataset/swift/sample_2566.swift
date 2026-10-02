import Foundation

func generate_sequence(_ n: Int) -> [Double] {
    return (0..<n).map { _ in Double.random(in: 0..<1) }
}

func calculate_pvalue(_ seq1: [Double], _ seq2: [Double]) -> Double {
    var combined = seq1 + seq2
    combined.sort()
    let n1 = seq1.count
    let n2 = seq2.count
    var count = 0
    for _ in 0..<10000 {
        combined.shuffle()
        let rank_sum = seq1.map { combined.firstIndex(of: $0)! }.reduce(0, +)
        if rank_sum <= n1 * (n1 + n2 + 1) / 2 {
            count += 1
        }
    }
    return Double(count) / 10000
}

func main() {
    let seq1 = generate_sequence(50)
    let seq2 = generate_sequence(50)
    let pvalue = calculate_pvalue(seq1, seq2)
    print(pvalue)
}

main()