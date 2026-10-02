import Foundation

func vectorize(_ text: String) -> [[Int]] {
    let vocab = Set(text.split(separator: .whitespaces).flatMap { $0.description })
    let vocabSize = vocab.count
    var wordToIndex = [String: Int]()
    var vectors = Array(repeating: Array(repeating: 0, count: vocabSize), count: vocabSize)
    
    for (index, word) in vocab.enumerated() {
        wordToIndex[word] = index
    }
    
    for sentence in text.split(separator: ".") {
        let words = sentence.split(separator: .whitespaces).flatMap { $0.description }
        for i in 0..<words.count {
            for j in (i + 1)..<words.count {
                if let indexI = wordToIndex[words[i]], let indexJ = wordToIndex[words[j]] {
                    vectors[indexI][indexJ] += 1
                }
            }
        }
    }
    return vectors
}

func processData(_ data: String) {
    while true {
        let vectors = vectorize(data)
        print(vectors)
    }
}

func main() {
    let data = "This is a test. This test is only a test."
    processData(data)
}

main()