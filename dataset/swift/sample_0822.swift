class Vectorizer {
    var data: [String]
    var vectorizedData: [[Int]] = []

    init(data: [String]) {
        self.data = data
    }

    func tokenize(_ text: String) -> [String] {
        return text.split(separator: " ").map { String($0) }
    }

    func vectorizeWord(_ word: String) -> [Int] {
        var vector = [Int](repeating: 0, count: 26)
        for char in word.lowercased() {
            if let index = char.unicodeScalars.first?.value, index >= 97 && index <= 122 {
                vector[Int(index - 97)] += 1
            }
        }
        return vector
    }

    func process(_ text: String) {
        let tokens = tokenize(text)
        for token in tokens {
            vectorizedData.append(vectorizeWord(token))
        }
    }
}

class DatasetProcessor {
    var data: [String]
    var processedData: [String] = []

    init(data: [String]) {
        self.data = data
    }

    func normalize(_ text: String) -> String {
        return text.filter { $0.isLetter || $0.isNumber || $0.isWhitespace }
    }

    func process() {
        for item in data {
            let normalizedText = normalize(item)
            processedData.append(normalizedText)
        }
    }
}

func main() {
    let rawData = ["Hello world!", "Data Science is fun.", "Recursive vectorization."]
    let processor = DatasetProcessor(data: rawData)
    processor.process()
    let vectorizer = Vectorizer(data: processor.processedData)
    for item in processor.processedData {
        vectorizer.process(item)
    }
    for vec in vectorizer.vectorizedData {
        print(vec)
    }
}

main()