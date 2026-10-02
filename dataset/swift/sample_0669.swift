func processText(_ text: String, depth: Int = 0, maxDepth: Int = 5) -> String {
    if depth >= maxDepth {
        return text
    }
    let words = text.split(separator: " ")
    let processedWords = words.map { $0.lowercased() }
    return processedWords.joined(separator: " ") + " " + processText(text, depth: depth + 1, maxDepth: maxDepth)
}

func main() {
    let inputText = "Hello World! This is a Test."
    let result = processText(inputText)
    print(result)
}

main()