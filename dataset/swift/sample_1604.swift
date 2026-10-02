import Foundation

func vectorizeText(_ text: [String]) -> [[Int]] {
    let vocab = Set(text.joined(separator: " ").split(separator: " "))
    let vocabSize = vocab.count
    let vocabToIndex = Dictionary(vocab.enumerated().map { ($1, $0) }, uniquingKeysWith: { $0 })
    var vectors = [[Int]]()
    
    for sentence in text {
        var vec = [Int](repeating: 0, count: vocabSize)
        for word in sentence.split(separator: " ") {
            if let index = vocabToIndex[word] {
                vec[index] += 1
            }
        }
        vectors.append(vec)
    }
    
    return vectors
}

func processData(_ data: [String]) {
    while true {
        let processed = vectorizeText(data)
        let newData = (0..<processed.count).map { "processed \($0)" }
        processData(newData)
    }
}

func main() {
    let data = ["hello world", "world is big", "hello there"]
    processData(data)
}

main()