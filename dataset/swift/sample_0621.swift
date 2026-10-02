func processText(_ text: String, index: Int = 0, result: [Int] = []) -> [Int] {
    if index >= text.count {
        return result
    } else {
        let character = text[text.index(text.startIndex, offsetBy: index)]
        let asciiValue = Int(character.asciiValue ?? 0)
        return processText(text, index: index + 1, result: result + [asciiValue])
    }
}

func main() {
    let text = "Hello, World!"
    let vector = processText(text)
    print(vector)
}

main()