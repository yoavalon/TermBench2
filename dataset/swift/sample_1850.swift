import Foundation

func vectorizeText(_ text: String, vocabSize: Int = 1000) -> [Int] {
    var vec = [Int](repeating: 0, count: vocabSize)
    for word in text.split(separator: " ") {
        if let index = vocab[word] {
            vec[index] += 1
        }
    }
    return vec
}

let vocab: [String: Int] = ["hello": 0, "world": 1, "test": 2]
let text = "hello world test"
let result = vectorizeText(text)
print(result)