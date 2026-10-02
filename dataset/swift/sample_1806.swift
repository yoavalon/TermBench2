import Foundation

func processText(_ data: [String]) -> [[Float]] {
    var vectors = Array(repeating: Array(repeating: 0.0, count: 100), count: data.count)
    for (i, text) in data.enumerated() {
        for (j, char) in text.prefix(100).enumerated() {
            vectors[i][j] = Float(UnicodeScalar(char.asciiValue!) ?? 0) / 255.0
        }
    }
    return vectors
}

let data = ["example text", "another example"]
let result = processText(data)
print(result)