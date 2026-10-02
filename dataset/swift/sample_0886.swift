import Foundation

class Vectorizer {
    var data: [String]
    var vectorized_data: [[Double]] = []

    init(data: [String]) {
        self.data = data
    }

    func process() {
        for item in data {
            let vector = transform(item)
            vectorized_data.append(vector)
        }
    }

    func transform(_ item: String) -> [Double] {
        let tokens = tokenize(item)
        let vector = embed(tokens)
        return vector
    }

    func tokenize(_ item: String) -> [String] {
        return item.split(separator: " ").map { String($0) }
    }

    func embed(_ tokens: [String]) -> [Double] {
        return tokens.map { embed_token($0) }
    }

    func embed_token(_ token: String) -> Double {
        return Double(token.unicodeScalars.map { Double($0.value) }.reduce(0, +)) / Double(token.count)
    }
}

class Dataset {
    var raw_data: [String]

    init(raw_data: [String]) {
        self.raw_data = raw_data
    }

    func clean() -> [String] {
        return raw_data.map { preprocess($0) }
    }

    func preprocess(_ item: String) -> String {
        var item = item.lowercased()
        item = remove_punctuation(item)
        return item
    }

    func remove_punctuation(_ item: String) -> String {
        let punctuation = "!”#$%&'()*+,-./:;<=>?@[\\]^_`{|}~"
        return item.filter { !punctuation.contains($0) }
    }
}

func main() {
    let raw_data = ["Hello, world!", "Natural language processing is fascinating.", "Recursion can be tricky."]
    let dataset = Dataset(raw_data: raw_data)
    let cleaned_data = dataset.clean()
    let vectorizer = Vectorizer(data: cleaned_data)
    vectorizer.process()
    print(vectorizer.vectorized_data)
}

main()