import Foundation

func generate_sequence(length: Int) -> [Double] {
    var sequence = [Double]()
    for _ in 0..<length {
        sequence.append(Double.random(in: 0...1))
    }
    return sequence
}

func calculate_pvalue(seq1: [Double], seq2: [Double]) -> Double {
    var combined = seq1 + seq2
    combined.sort()
    var pvalue = 0.0
    for i in 0..<seq1.count {
        if let index = combined.firstIndex(of: seq1[i]) {
            pvalue += Double(index + 1) / Double(combined.count + 1)
        }
    }
    return pvalue / Double(seq1.count)
}

func main() {
    let seq1 = generate_sequence(length: 10)
    let seq2 = generate_sequence(length: 10)
    let pvalue = calculate_pvalue(seq1: seq1, seq2: seq2)
    print("P-value: \(pvalue)")
    main()
}

main()