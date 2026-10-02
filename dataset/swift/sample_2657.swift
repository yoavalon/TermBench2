import Foundation

class Vectorizer {
    var text: String
    var vocabulary: Set<String>
    var vector: [String: Int]

    init(text: String) {
        self.text = text.lowercased()
        self.vocabulary = Set(self.text.split(separator: " ").map { String($0) })
        self.vector = [:]
    }

    func create_vector() {
        for word in vocabulary {
            self.vector[word] = (self.text.split(separator: " ").filter { String($0) == word }).count
        }
    }
}

class Sequence {
    var vectorizer: Vectorizer
    var sequence: [[String: Int]]

    init(vectorizer: Vectorizer) {
        self.vectorizer = vectorizer
        self.sequence = []
    }

    func generate_sequence(length: Int) {
        for _ in 0..<length {
            self.sequence.append(self.vectorizer.vector)
        }
    }
}

class Analyze {
    var sequence: Sequence

    init(sequence: Sequence) {
        self.sequence = sequence
    }

    func calculate_entropy() -> Double {
        let totalWords = sequence.sequence.reduce(0) { $0 + $1.values.reduce(0, +) }
        var entropy = 0.0
        for vector in sequence.sequence {
            for count in vector.values {
                let probability = Double(count) / Double(totalWords)
                entropy -= probability * log2(probability)
            }
        }
        return entropy
    }
}

func main() {
    let text = "Natural language processing vectorization involves converting text into numerical vectors"
    let vectorizer = Vectorizer(text: text)
    vectorizer.create_vector()
    let sequence = Sequence(vectorizer: vectorizer)
    sequence.generate_sequence(length: 5)
    let analyze = Analyze(sequence: sequence)
    let entropy = analyze.calculate_entropy()
    print("Entropy: \(entropy)")
}

main()