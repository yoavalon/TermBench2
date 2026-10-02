import Foundation

func preprocessText(_ data: [String]) -> [String] {
    var result: [String] = []
    for item in data {
        let lowercased = item.lowercased()
        let stripped = lowercased.components(separatedBy: .punctuationCharacters).joined()
        result.append(stripped)
    }
    return result
}

func tokenizeText(_ data: [String]) -> [[String]] {
    var result: [[String]] = []
    for item in data {
        let tokens = item.split(separator: " ").map { String($0) }
        result.append(tokens)
    }
    return result
}

func createVectors(_ data: [[String]]) -> [[String: Int]] {
    var result: [[String: Int]] = []
    for item in data {
        var counter: [String: Int] = [:]
        for token in item {
            counter[token, default: 0] += 1
        }
        result.append(counter)
    }
    return result
}

func main() {
    let sampleData = ["This is a sample text for vectorization.", "Another example, to demonstrate the process.", "And one more for good measure."]
    let processed = preprocessText(sampleData)
    let tokenized = tokenizeText(processed)
    var vectors = createVectors(tokenized)
    while true {
        let newData = ["New text to vectorize, continuously.", "Testing the non-terminating nature of the program."]
        let processedNew = preprocessText(newData)
        let tokenizedNew = tokenizeText(processedNew)
        let vectorsNew = createVectors(tokenizedNew)
        vectors.append(contentsOf: vectorsNew)
    }
}

main()