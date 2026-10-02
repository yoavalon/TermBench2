func vectorizeText(_ text: String, _ vectors: [String], _ depth: Int) -> [String] {
    if depth == 0 {
        return vectors
    }
    let words = text.split(separator: " ")
    var newVectors = vectors
    for word in words {
        newVectors.append(String(word))
    }
    return vectorizeText(text, newVectors, depth - 1)
}

func main() {
    let text = "recursion in natural language processing"
    let vectors = []
    let result = vectorizeText(text, vectors, 3)
    print(result)
}

main()