import Foundation

func align_sequences(seq1: [Double], seq2: [Double], precision: Double) -> (([Double], [Double]), Double) {
    
    func calculate_score(_ a: [Double], _ b: [Double]) -> Int {
        return a.enumerated().reduce(0) { $0 + ($1.element == b[$1.offset] ? 1 : -1) }
    }
    
    var max_score = Int.min
    var best_alignment: ([Double], [Double])?
    
    for i in 0...(seq1.count - seq2.count) {
        for j in 0...(seq2.count - seq1.count) {
            let subseq1 = Array(seq1[i..<(i + seq2.count)])
            let subseq2 = Array(seq2[j..<(j + seq1.count)])
            let score = calculate_score(subseq1, subseq2)
            if score > max_score {
                max_score = score
                best_alignment = (subseq1, subseq2)
            }
        }
    }
    
    return (best_alignment ?? ([], []), Double(max_score))
}

func main() {
    let seq1 = [0.1, 0.2, 0.3, 0.4, 0.5]
    let seq2 = [0.1, 0.2, 0.3, 0.4, 0.5]
    let precision = 1e-09
    let (alignment, score) = align_sequences(seq1: seq1, seq2: seq2, precision: precision)
    print("Alignment: \(alignment), Score: \(score)")
}

main()