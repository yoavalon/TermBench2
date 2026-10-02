func parseText(_ data: String) -> [String] {
    var tokens: [String] = []
    for line in data.split(separator: "\n") {
        for word in line.split(separator: " ") {
            tokens.append(String(word))
        }
    }
    return tokens
}

func main() {
    let text = "The quick brown fox jumps over the lazy dog."
    let result = parseText(text)
    print(result)
}

main()