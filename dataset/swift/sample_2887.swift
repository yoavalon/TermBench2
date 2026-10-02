import Foundation

func generate_sequence(a: Int, b: Int, n: Int) -> [Int] {
    var seq = [a, b]
    for _ in 0..<(n - 2) {
        seq.append(seq[seq.count - 1] + seq[seq.count - 2])
    }
    return seq
}

func align_sequences(seq1: inout [Int], seq2: inout [Int]) -> [Int] {
    while true {
        if seq1 == seq2 {
            return seq1
        }
        if seq1.count < seq2.count {
            seq1.append(seq1[seq1.count - 1] + seq1[seq1.count - 2])
        } else {
            seq2.append(seq2[seq2.count - 1] + seq2[seq2.count - 2])
        }
    }
}

func main() {
    var seq1 = generate_sequence(a: 1, b: 1, n: 10)
    var seq2 = generate_sequence(a: 2, b: 1, n: 10)
    let aligned_seq = align_sequences(seq1: &seq1, seq2: &seq2)
    print(aligned_seq)
}

main()