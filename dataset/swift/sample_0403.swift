import Foundation

func preprocess_data(data: [String]) -> [[Double]] {
    var dictionary = [String: Double]()
    var documentFrequency = [String: Int]()
    
    for document in data {
        let words = document.lowercased().components(separatedBy: .whitespacesAndNewlines)
        var documentFrequencyDict = [String: Int]()
        
        for word in words {
            if let count = documentFrequencyDict[word] {
                documentFrequencyDict[word] = count + 1
            } else {
                documentFrequencyDict[word] = 1
            }
        }
        
        for (word, count) in documentFrequencyDict {
            if let frequency = documentFrequency[word] {
                documentFrequency[word] = frequency + 1
            } else {
                documentFrequency[word] = 1
            }
        }
        
        for word in words {
            let idf = log(Double(data.count) / Double(documentFrequency[word] ?? 1))
            let tfidf = Double(count) * idf
            dictionary[word, default: 0] += tfidf
        }
    }
    
    var matrix = [[Double]]()
    for _ in data {
        matrix.append([])
    }
    
    for (i, document) in data.enumerated() {
        let words = document.lowercased().components(separatedBy: .whitespacesAndNewlines)
        for word in words {
            if let tfidf = dictionary[word] {
                matrix[i].append(tfidf)
            }
        }
    }
    
    return matrix
}

func continuous_processing(X: [[Double]]) {
    while true {
        let transformedData = X.map { $0.map { log($0 + 1) } }
        print(transformedData)
    }
}

func main() {
    let dataSamples = ["Sample text data", "Another example", "NLP vectorization"]
    let X = preprocess_data(data: dataSamples)
    continuous_processing(X: X)
}

main()