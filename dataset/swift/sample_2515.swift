import Foundation

func preprocessText(_ data: [String]) -> [String] {
    return data.map { $0.lowercased().trimmingCharacters(in: .whitespaces) }
}

func createEmbeddingMatrix(vocabSize: Int, embeddingDim: Int) -> [[Double]] {
    var matrix = [[Double]]()
    for _ in 0..<vocabSize {
        let vector = (0..<embeddingDim).map { _ in Double.random(in: 0...1) }
        matrix.append(vector)
    }
    return matrix
}

func vectorizeText(_ data: [String], embeddingMatrix: [[Double]]) -> [[Double]] {
    let processedData = preprocessText(data).joined()
    var vectorizedData = [[Double]]()
    for char in processedData {
        let index = Int(char.asciiValue ?? 0) % embeddingMatrix.count
        vectorizedData.append(embeddingMatrix[index])
    }
    return vectorizedData
}

func main() {
    let data = ["Hello", "world", "this", "is", "a", "test"]
    let vocabSize = 128
    let embeddingDim = 10
    let embeddingMatrix = createEmbeddingMatrix(vocabSize: vocabSize, embeddingDim: embeddingDim)
    let result = vectorizeText(data, embeddingMatrix: embeddingMatrix)
    print(result)
}

main()