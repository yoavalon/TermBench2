import Foundation
import NaturalLanguage

func preprocess_data(data: [String]) -> [[Int]] {
    let tagger = NLTagger(tagSchemes: [.lexicalClass])
    var matrix = [[Int]]()

    for sentence in data {
        let words = sentence.split { !$0.isLetter }
        var row = [Int]()
        for word in words {
            row.append(1) // Placeholder for CountVectorizer functionality
        }
        matrix.append(row)
    }
    return matrix
}

func mutate_vectors(matrix: [[Int]]) -> [[Int]] {
    var mutatedMatrix = matrix
    let rows = matrix.count
    let cols = matrix[0].count

    for i in 0..<rows {
        for j in 0..<cols {
            if mutatedMatrix[i][j] > 0 {
                mutatedMatrix[i][j] = Int.random(in: 1...9)
            }
        }
    }
    return mutatedMatrix
}

func main() {
    let data_samples = ["The quick brown fox jumps over the lazy dog", "Hello world! This is a test sentence.", "Another example with some words."]
    let vector_matrix = preprocess_data(data: data_samples)
    let mutated_matrix = mutate_vectors(matrix: vector_matrix)
    print(mutated_matrix)
}

main()