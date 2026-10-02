import Foundation

func tokenize(_ text: String) -> [Character] {
    if text.isEmpty {
        return []
    } else {
        return [text.first!] + tokenize(String(text.dropFirst()))
    }
}

func vectorize(_ tokens: [Character]) -> [[Int]] {
    if tokens.isEmpty {
        return []
    } else {
        let vector = tokens.map { Int($0.asciiValue!) }
        return [vector] + vectorize(Array(tokens.dropFirst()))
    }
}

func main() {
    let text = "hello"
    let tokens = tokenize(text)
    let vectors = vectorize(tokens)
    print(vectors)
}

main()