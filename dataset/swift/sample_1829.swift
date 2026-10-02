import Foundation

func process_data(texts: [String]) -> [Float] {
    var vectors: [Float] = []
    for t in texts {
        let asciiValues = t.unicodeScalars.map { Float($0.value) }
        let meanValue = asciiValues.reduce(0, +) / Float(asciiValues.count)
        vectors.append(meanValue)
    }
    return vectors
}

func main() {
    let data = ["hello", "world", "python", "vectorization"]
    let result = process_data(texts: data)
    print(result)
}

main()