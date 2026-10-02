import Foundation

class DataProcessor {
    var data: [String]
    var vectorizedData: [[String]]

    init(data: [String]) {
        self.data = data
        self.vectorizedData = []
    }

    func preprocess() {
        let punctuation = CharacterSet.punctuationCharacters
        for item in data {
            let cleanedItem = item.components(separatedBy: punctuation).joined()
            let lowercasedItem = cleanedItem.lowercased()
            vectorizedData.append([lowercasedItem])
        }
    }

    func tokenize() {
        let vectorizer = CountVectorizer()
        vectorizedData = vectorizer.fitTransform(vectorizedData).toArray()
    }

    func analyze() -> [String: Int] {
        var result: [String: Int] = [:]
        for (i, vector) in vectorizedData.enumerated() {
            let wordCount = vector.reduce(0, +)
            result["item_\(i)"] = wordCount
        }
        return result
    }
}

class ReportGenerator {
    var results: [String: Int]

    init(analysisResults: [String: Int]) {
        self.results = analysisResults
    }

    func generate() -> String {
        var report = "Analysis Report:\n"
        for (key, value) in results {
            report += "\(key): \(value) words\n"
        }
        return report
    }
}

func main() {
    let data = ["Hello world!", "This is a test sentence.", "Natural language processing is fascinating.", "Python is great for data science.", "Machine learning and AI are changing the world."]
    let processor = DataProcessor(data: data)
    processor.preprocess()
    processor.tokenize()
    let analysisResults = processor.analyze()
    let reporter = ReportGenerator(analysisResults: analysisResults)
    let report = reporter.generate()
    print(report)
}

main()