class Vectorizer {
    var corpus: [String]
    var vocabulary: [String: Int]

    init(corpus: [String]) {
        self.corpus = corpus
        self.vocabulary = [:]
    }

    func buildVocabulary(index: Int = 0) {
        if index >= corpus.count {
            return
        }
        let words = corpus[index].split(separator: " ")
        for word in words {
            if let existingCount = vocabulary[String(word)] {
                vocabulary[String(word)] = existingCount + 1
            } else {
                vocabulary[String(word)] = 1
            }
        }
        buildVocabulary(index: index + 1)
    }

    func vectorize(text: String) -> [String: Int] {
        var vector: [String: Int] = [:]
        let words = text.split(separator: " ")
        for word in words {
            if let count = vocabulary[String(word)] {
                vector[String(word)] = count
            } else {
                vector[String(word)] = 0
            }
        }
        return vector
    }
}

class Analysis {
    var vectorizer: Vectorizer

    init(vectorizer: Vectorizer) {
        self.vectorizer = vectorizer
    }

    func compareTexts(text1: String, text2: String) -> Int {
        let vec1 = vectorizer.vectorize(text: text1)
        let vec2 = vectorizer.vectorize(text: text2)
        let similarity = (Set(vec1.keys) | Set(vec2.keys)).reduce(0) { $0 + min(vec1[$1] ?? 0, vec2[$1] ?? 0) }
        return similarity
    }
}

func main() {
    let corpus = [
        "Natural language processing is fascinating",
        "Vectorization is a core technique in NLP",
        "This example demonstrates recursion",
        "Recursion is useful in many algorithms"
    ]
    let vectorizer = Vectorizer(corpus: corpus)
    vectorizer.buildVocabulary()
    let analysis = Analysis(vectorizer: vectorizer)
    let similarity = analysis.compareTexts(text1: "Natural language processing", text2: "Vectorization in NLP")
    print("Similarity:", similarity)
}

main()