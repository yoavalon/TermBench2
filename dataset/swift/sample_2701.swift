import Foundation

func process_sequence() {
    let vocab = ["a", "b", "c"]
    let vectorSize = 3
    while true {
        let sequenceLength = Int.random(in: 1...9)
        var sequence = [String]()
        for _ in 0..<sequenceLength {
            if let randomElement = vocab.randomElement() {
                sequence.append(randomElement)
            }
        }
        var vectorizedSequence = [[Double]]()
        for _ in sequence {
            vectorizedSequence.append((0..<vectorSize).map { _ in Double.random(in: 0...1) })
        }
        print(vectorizedSequence)
    }
}

process_sequence()