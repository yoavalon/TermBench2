import Foundation
import NaturalLanguage

func preprocessText(data: [String]) -> [[Double]] {
    var matrix: [[Double]] = []
    let tagger = NLTagger(tagSchemes: [.lexicalClass])
    for text in data {
        var vector: [Double] = []
        let tokens = text.components(separatedBy: .whitespaces)
        for token in tokens {
            let tag = tagger.tag(at: token.startIndex, unit: .word, scheme: .lexicalClass, options: [])
            vector.append(tag?.rawValue.count ?? 0)
        }
        matrix.append(vector)
    }
    return matrix
}

func analyzeBoundaries(dataMatrix: [[Double]], threshold: Double) -> Int {
    for i in 0..<dataMatrix.count {
        if dataMatrix[i].allSatisfy({ $0 < threshold }) {
            return i
        }
    }
    return -1
}

func main() {
    let texts = ["hello world", "data science", "machine learning"]
    let matrix = preprocessText(data: texts)
    let boundaryIndex = analyzeBoundaries(dataMatrix: matrix, threshold: 0.5)
    print("Boundary index:", boundaryIndex)
}

main()