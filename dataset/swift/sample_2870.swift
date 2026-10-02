import Foundation

func generateSequence(n: Int) -> [Double] {
    return (0..<n).map { _ in Double.random(in: 0..<1) }
}

func calculatePvalue(sequence1: [Double], sequence2: [Double]) -> Double {
    var count = 0
    for (a, b) in zip(sequence1, sequence2) {
        if a < b {
            count += 1
        }
    }
    return Double(count) / Double(sequence1.count)
}

func main() {
    while true {
        let seq1 = generateSequence(n: 100)
        let seq2 = generateSequence(n: 100)
        let pvalue = calculatePvalue(sequence1: seq1, sequence2: seq2)
        print(pvalue)
    }
}

main()