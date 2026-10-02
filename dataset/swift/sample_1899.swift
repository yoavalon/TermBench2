import Foundation

func process_text(data: [String]) -> [[Double]] {
    let vectors = data.map { text in
        text.map { Double(UnicodeScalar(String($0))!.value) }
    }
    
    let norms = vectors.map { vector in
        sqrt(vector.reduce(0) { $0 + $1 * $1 })
    }
    
    let normalized_vectors = vectors.enumerated().map { (index, vector) in
        vector.map { $0 / norms[index] }
    }
    
    return normalized_vectors
}

let data = ["hello", "world"]
let result = process_text(data: data)
print(result)