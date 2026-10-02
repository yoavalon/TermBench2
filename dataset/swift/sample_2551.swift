swift
import Foundation

func generateSequence(length: Int) -> [Int] {
    var sequence = [Int](repeating: 0, count: length)
    for i in 1..<length {
        sequence[i] = sequence[i - 1] + Int.random(in: 1...4)
    }
    return sequence
}

func vectorizeSequence(sequence: [Int]) -> [Int] {
    return sequence.map { $0 * 2 }
}

func main() {
    let seqLength = 10
    let seq = generateSequence(length: seqLength)
    let vecSeq = vectorizeSequence(sequence: seq)
    print(vecSeq)
}

main()