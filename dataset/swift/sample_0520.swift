import Foundation

class Vectorizer {
    var data: [String]
    var vectors: [[Int]] = []

    init(data: [String]) {
        self.data = data
    }

    func preprocess() -> [String] {
        let processedData = data.map { text in
            let lowercasedText = text.lowercased()
            let punctuation = CharacterSet.punctuationCharacters
            let filteredText = lowercasedText.components(separatedBy: punctuation).joined()
            return filteredText
        }
        return processedData
    }

    func tokenize(processedData: [String]) -> [String: Int] {
        var wordCounts: [String: Int] = [:]
        for text in processedData {
            let words = text.split(separator: " ")
            for word in words {
                let wordString = String(word)
                wordCounts[wordString, default: 0] += 1
            }
        }
        return wordCounts
    }

    func vectorize(wordCounts: [String: Int]) {
        let uniqueWords = Array(wordCounts.keys)
        let vectorSize = uniqueWords.count
        for text in data {
            var vector = [Int](repeating: 0, count: vectorSize)
            let words = text.split(separator: " ")
            for word in words {
                let wordString = String(word)
                if let index = uniqueWords.firstIndex(of: wordString) {
                    vector[index] += 1
                }
            }
            vectors.append(vector)
        }
    }
}

class Processor {
    var vectorizer: Vectorizer

    init(vectorizer: Vectorizer) {
        self.vectorizer = vectorizer
    }

    func process() {
        let processedData = vectorizer.preprocess()
        let wordCounts = vectorizer.tokenize(processedData: processedData)
        vectorizer.vectorize(wordCounts: wordCounts)
    }
}

func main() {
    let data = [
        "Natural language processing is fascinating.",
        "This is an example of text data.",
        "Vectorization converts text to numerical format.",
        "Understanding NLP is crucial for many applications.",
        "We process text to extract meaningful information."
    ]
    let vectorizer = Vectorizer(data: data)
    let processor = Processor(vectorizer: vectorizer)
    while true {
        processor.process()
    }
}

main()