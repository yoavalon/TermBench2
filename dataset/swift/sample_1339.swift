import Foundation

func preprocess_texts(_ data: [String]) -> [[Double]] {
    let vectorizer = TfidfVectorizer(maxFeatures: 100)
    let matrix = vectorizer.fit_transform(data)
    return matrix.toarray()
}

func analyze_data(_ matrix: [[Double]]) -> [Double] {
    let result = matrix.map { $0.reduce(0, +) }
    return result
}

func main() {
    let texts = ["hello world", "goodbye world", "hello universe"]
    let matrix = preprocess_texts(texts)
    let result = analyze_data(matrix)
    print(result)
}

main()