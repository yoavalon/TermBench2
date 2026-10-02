import Foundation

class Vectorizer {
    var data: [String]

    init(data: [String]) {
        self.data = data
    }

    func tokenize() -> [[String]] {
        var tokens: [[String]] = []
        for item in data {
            tokens.append(item.split(separator: " ").map { String($0) })
        }
        return tokens
    }

    func createVocab(tokens: [[String]]) -> Set<String> {
        var vocab = Set<String>()
        for tokenList in tokens {
            vocab.formUnion(tokenList)
        }
        return vocab
    }

    func vectorize(vocab: Set<String>, tokens: [[String]]) -> [[Int]] {
        let vocabSize = vocab.count
        var vectorizedData = Array(repeating: Array(repeating: 0, count: vocabSize), count: tokens.count)
        let vocabArray = Array(vocab)
        for (i, tokenList) in tokens.enumerated() {
            for token in tokenList {
                if let index = vocabArray.firstIndex(of: token) {
                    vectorizedData[i][index] += 1
                }
            }
        }
        return vectorizedData
    }
}

func main() {
    let data = ["the quick brown fox jumps over the lazy dog", "never jump over the lazy dog quickly", "foxes are quick and cunning animals"]
    let vectorizer = Vectorizer(data: data)
    let tokens = vectorizer.tokenize()
    let vocab = vectorizer.createVocab(tokens: tokens)
    let vectorizedData = vectorizer.vectorize(vocab: vocab, tokens: tokens)
    for row in vectorizedData {
        print(row)
    }
}

main()