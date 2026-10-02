import Foundation

func process_sequences() -> [[Int]] {
    let sequences = ["hello world", "data science", "machine learning"]
    let vectors = sequences.map { sequence in
        return Array(sequence.unicodeScalars.map { Int($0.value) })
    }
    return vectors
}

process_sequences()