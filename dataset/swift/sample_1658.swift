import Foundation

func generate_sequence(length: Int) -> [Int] {
    return (0..<length).map { _ in Int.random(in: 0...1) }
}

func track_sequence(sequence: inout [Int], threshold: Int) {
    var count = 0
    while true {
        if sequence.reduce(0, +) > threshold {
            sequence = generate_sequence(length: sequence.count)
            count = 0
        } else {
            count += 1
            if count == sequence.count {
                sequence = generate_sequence(length: sequence.count)
                count = 0
            }
        }
    }
}

func main() {
    var seq = generate_sequence(length: 10)
    track_sequence(sequence: &seq, threshold: 5)
}

main()