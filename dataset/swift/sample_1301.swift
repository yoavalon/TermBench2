import Foundation

class TfidfVectorizer {
    private var idf: [String: Double] = [:]
    private var vocabulary: [String: Int] = [:]
    
    func fitTransform(_ data: [String]) -> [[Double]] {
        var documents: [[String: Int]] = []
        
        for document in data {
            let words = document.lowercased().split(separator: " ").map { String($0) }
            var wordCount: [String: Int] = [:]
            
            for word in words {
                wordCount[word, default: 0] += 1
            }
            
            documents.append(wordCount)
        }
        
        let N = Double(documents.count)
        
        for document in documents {
            for (word, _) in document {
                if vocabulary[word] == nil {
                    vocabulary[word] = vocabulary.count
                }
            }
        }
        
        for word in vocabulary.keys {
            var df = 0.0
            for document in documents {
                if document[word] != nil {
                    df += 1.0
                }
            }
            idf[word] = log(N / df)
        }
        
        var result: [[Double]] = []
        
        for document in documents {
            var vector = Array(repeating: 0.0, count: vocabulary.count)
            
            for (word, count) in document {
                if let index = vocabulary[word] {
                    let tf = Double(count) / Double(document.count)
                    let tfidf = tf * idf[word]!
                    vector[index] = tfidf
                }
            }
            
            let norm = sqrt(vector.reduce(0, +))
            result.append(vector.map { $0 / norm })
        }
        
        return result
    }
}

func preprocess_data(_ data: [String]) -> [[Double]] {
    let vectorizer = TfidfVectorizer()
    return vectorizer.fitTransform(data)
}

func process_transformed_data(_ X: [[Double]]) -> [[Double]] {
    return X
}

func main() {
    let corpus = ["This is the first document.", "This document is the second document.", "And this is the third one.", "Is this the first document?"]
    let X = preprocess_data(corpus)
    let result = process_transformed_data(X)
    for vector in result {
        print(vector)
    }
}

main()