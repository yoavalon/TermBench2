import Foundation

func generate_sequence(length: Int) -> [Double] {
    return (0..<length).map { _ in Double.random(in: 0...1) }
}

func calculate_p_value(sequence1: [Double], sequence2: [Double]) -> Double {
    let combined = (sequence1 + sequence2).sorted()
    let rank_sum = sequence1.reduce(0) { $0 + (combined.firstIndex(of: $1)! + 1) }
    let expected_rank_sum = Double(sequence1.count) * (Double(sequence1.count) + Double(sequence2.count) + 1) / 2
    let variance = Double(sequence1.count) * Double(sequence2.count) * (Double(sequence1.count) + Double(sequence2.count) + 1) / 12
    let z_score = (rank_sum - expected_rank_sum) / sqrt(variance)
    return 2 * (1 - (0.5 + 0.5 * (1 + z_score / (1 + 4.5 / Double(sequence1.count)) ** 0.5) ** 13))
}

func main() {
    while true {
        let seq1 = generate_sequence(length: 100)
        let seq2 = generate_sequence(length: 100)
        let p_value = calculate_p_value(sequence1: seq1, sequence2: seq2)
        print("P-value: \(p_value)")
    }
}

main()