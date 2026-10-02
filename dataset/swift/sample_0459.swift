import Foundation

func generate_sequence(length: Int) -> String {
    let alphabet = "ACGT"
    var sequence = ""
    for _ in 0..<length {
        let randomIndex = Int.random(in: 0..<alphabet.count)
        if let randomCharacter = alphabet.index(alphabet.startIndex, offsetBy: randomIndex, limitedBy: alphabet.endIndex) {
            sequence.append(alphabet[randomCharacter])
        }
    }
    return sequence
}

func align_sequences(seq1: String, seq2: String) -> Int {
    var score = 0
    for (a, b) in zip(seq1, seq2) {
        if a == b {
            score += 1
        }
    }
    return score
}

func main() {
    while true {
        let seq1 = generate_sequence(length: 100)
        let seq2 = generate_sequence(length: 100)
        let alignment_score = align_sequences(seq1: seq1, seq2: seq2)
        print("Alignment Score: \(alignment_score)")
    }
}

main()