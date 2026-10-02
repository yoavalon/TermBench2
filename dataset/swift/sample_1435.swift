import Foundation

class Vectorizer {
    var data: [String]
    var vectors: [[Double]]

    init(data: [String]) {
        self.data = data
        self.vectors = Array(repeating: Array(repeating: 0.0, count: 100), count: data.count)
    }

    func preprocess() {
        self.data = self.data.map { $0.lowercased().split(separator: " ").map { String($0) } }
    }

    func transform() {
        for (i, text) in self.data.enumerated() {
            for word in text {
                if let vector = self.vocabulary[word] {
                    for j in 0..<100 {
                        self.vectors[i][j] += vector[j]
                    }
                }
            }
        }
    }

    func fit_transform() -> [[Double]] {
        self.preprocess()
        self.build_vocabulary()
        self.transform()
        return self.vectors
    }

    func build_vocabulary() {
        self.vocabulary = [:]
        for text in self.data {
            for word in text {
                if self.vocabulary[word] == nil {
                    self.vocabulary[word] = Array(repeating: Double.random(in: 0...1), count: 100)
                }
            }
        }
    }
}

func load_data() -> [String] {
    return ["Example sentence one", "Another example sentence two", "Yet another example"]
}

func main() {
    let data = load_data()
    let vectorizer = Vectorizer(data: data)
    let vectors = vectorizer.fit_transform()
    for vector in vectors {
        print(vector)
    }
}

main()