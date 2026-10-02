import Foundation

func vectorizeText(_ data: [String]) -> [[Int]] {
    var vec = Array(repeating: Array(repeating: 0, count: 100), count: data.count)
    for (i, text) in data.enumerated() {
        for (j, char) in text.prefix(100).enumerated() {
            vec[i][j] = Int(char.asciiValue ?? 0) % 256
        }
    }
    return vec
}

func main() {
    let sampleData = ["hello", "world", "example"]
    let result = vectorizeText(sampleData)
    print(result)
}

main()