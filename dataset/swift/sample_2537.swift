import Foundation

func generateSequence(n: Int) -> [Double] {
    var seq = [Double]()
    for _ in 0..<n {
        seq.append(Double.random(in: 0...1))
    }
    seq.sort()
    return seq
}

func calculatePValues(seq1: [Double], seq2: [Double], k: Int) -> [Double] {
    var pValues = [Double]()
    for _ in 0..<k {
        var shuffledSeq1 = seq1.shuffled()
        var shuffledSeq2 = seq2.shuffled()
        let diff = shuffledSeq1.enumerated().filter { $0.element > shuffledSeq2[$0.offset] }.count
        pValues.append(Double(diff) / Double(seq1.count))
    }
    return pValues
}

func main() {
    let seq1 = generateSequence(n: 50)
    let seq2 = generateSequence(n: 50)
    let pValues = calculatePValues(seq1: seq1, seq2: seq2, k: 1000)
    print(pValues)
}

main()