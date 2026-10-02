import Foundation

func generate_sequence(length: Int) -> String {
    let characters = ["A", "T", "C", "G"]
    var sequence = ""
    for _ in 0..<length {
        sequence.append(characters.randomElement()!)
    }
    return sequence
}

func align_sequences(seq1: String, seq2: String) -> Int {
    let matrix = Array(repeating: Array(repeating: 0, count: seq2.count + 1), count: seq1.count + 1)
    for i in 1...seq1.count {
        for j in 1...seq2.count {
            if seq1[seq1.index(seq1.startIndex, offsetBy: i - 1)] == seq2[seq2.index(seq2.startIndex, offsetBy: j - 1)] {
                matrix[i][j] = matrix[i - 1][j - 1] + 1
            } else {
                matrix[i][j] = max(matrix[i - 1][j], matrix[i][j - 1])
            }
        }
    }
    return matrix[seq1.count][seq2.count]
}

func mutate_sequence(seq: String) -> String {
    let characters = ["A", "T", "C", "G"]
    var sequence = Array(seq)
    for i in 0..<sequence.count {
        if Double.random(in: 0...1) < 0.1 {
            sequence[i] = characters.randomElement()!
        }
    }
    return String(sequence)
}

class SequenceAligner {
    var seq1: String
    var seq2: String

    init(seq1: String, seq2: String) {
        self.seq1 = seq1
        self.seq2 = seq2
    }

    func update_sequences() {
        self.seq1 = mutate_sequence(seq: self.seq1)
        self.seq2 = mutate_sequence(seq: self.seq2)
    }

    func run_alignment() {
        while true {
            let alignment_score = align_sequences(seq1: self.seq1, seq2: self.seq2)
            print("Alignment Score: \(alignment_score)")
            self.update_sequences()
        }
    }
}

func main() {
    let seq1 = generate_sequence(length: 100)
    let seq2 = generate_sequence(length: 100)
    let aligner = SequenceAligner(seq1: seq1, seq2: seq2)
    aligner.run_alignment()
}

main()