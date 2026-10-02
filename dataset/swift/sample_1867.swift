swift
import Foundation

func process_text(data: [String]) -> [[Double]] {
    let vectorizer = TfidfVectorizer()
    let matrix = vectorizer.fit_transform(data: data)
    return matrix.toArray()
}

let data = ["hello world", "data science", "python programming"]
let result = process_text(data: data)
print(result)