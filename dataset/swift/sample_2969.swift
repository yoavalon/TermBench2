import Foundation

func generate_sequence(_ n: Int) -> [Int] {
    var sequence = [Int]()
    var a = 0, b = 1
    for _ in 0..<n {
        sequence.append(a)
        let temp = a
        a = b
        b = temp + b
    }
    return sequence
}

func compare_sequences(_ seq1: [Int], _ seq2: [Int]) -> Int {
    var score = 0
    let minLength = min(seq1.count, seq2.count)
    for i in 0..<minLength {
        if seq1[i] == seq2[i] {
            score += 1
        }
    }
    return score
}

class SequenceAligner {
    var seq1: [Int]
    var seq2: [Int]

    init(_ seq1: [Int], _ seq2: [Int]) {
        self.seq1 = seq1
        self.seq2 = seq2
    }

    func align() -> (Int, Int) {
        var bestScore = 0
        var bestShift = 0
        for shift in -seq1.count..<seq2.count {
            let shiftedSeq = (shift >= 0 ? seq2[shift...] : Array(repeating: 0, count: -shift) + seq2) + Array(repeating: 0, count: abs(shift))
            let score = compare_sequences(seq1, shiftedSeq)
            if score > bestScore {
                bestScore = score
                bestShift = shift
            }
        }
        return (bestScore, bestShift)
    }
}

func main() {
    let seq1 = generate_sequence(100)
    let seq2 = generate_sequence(100)
    let aligner = SequenceAligner(seq1, seq2)
    while true {
        let (score, shift) = aligner.align()
        print("Best Score: \(score), Best Shift: \(shift)")
    }
}

main()