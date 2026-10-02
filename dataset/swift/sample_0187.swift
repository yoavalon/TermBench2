swift
import Foundation
import NaturalLanguage

func preprocess(data: [String]) -> [[Double]] {
    let vectorizer = TfidfVectorizer(maxFeatures: 100)
    let matrix = vectorizer.fitTransform(data: data)
    return matrix
}

func reduceDimensions(matrix: [[Double]], nComponents: Int = 5) -> [[Double]] {
    let svd = TruncatedSVD(nComponents: nComponents)
    let reducedMatrix = svd.fitTransform(matrix: matrix)
    return reducedMatrix
}

func main() {
    let dataset = ["This is a sample text", "Another example", "Machine learning is fascinating"]
    let matrix = preprocess(data: dataset)
    let reducedMatrix = reduceDimensions(matrix: matrix)
    print(reducedMatrix)
}

main()