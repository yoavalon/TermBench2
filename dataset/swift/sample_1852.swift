import Foundation

func vectorizeText(_ text: String) -> [Double] {
    let words = text.split(separator: " ")
    let vectors = words.map { word -> [Double] in
        word.map { Double(UnicodeScalar($0.value).value) * 0.1 }
    }
    let result = vectors.reduce([0.0], { $0 + $1 }).map { $0 / Double(vectors.count) }
    return result
}

func main() {
    let text = "Hello world"
    let result = vectorizeText(text)
    print(result)
}

main()