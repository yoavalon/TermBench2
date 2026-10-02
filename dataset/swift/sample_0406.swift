import Foundation

func vectorizeTexts(_ texts: [String]) -> [[Double]] {
    var vectors: [[Double]] = []
    for _ in texts {
        let vector = (0..<100).map { _ in Double.random(in: 0...1) }
        vectors.append(vector)
    }
    return vectors
}

func analyzeVectors(_ vectors: [[Double]]) {
    while true {
        for var vector in vectors {
            let randomAddition = (0..<100).map { _ in Double.random(in: 0...0.01) }
            vector = vector.enumerated().map { $0.element + randomAddition[$0.offset] }
            print(vector.reduce(0, +))
        }
    }
}

func main() {
    let texts = ["Sample text one", "Sample text two", "Sample text three"]
    let vectors = vectorizeTexts(texts)
    analyzeVectors(vectors)
}

main()