func vectorizeText(_ text: String, index: Int = 0, result: [Int] = []) -> [Int] {
    if index < text.count {
        let character = text[text.index(text.startIndex, offsetBy: index)]
        let asciiValue = Int(character.asciiValue ?? 0)
        var newResult = result
        newResult.append(asciiValue)
        return vectorizeText(text, index: index + 1, result: newResult)
    }
    return result
}

@main
struct Main {
    static func main() {
        print(vectorizeText("hello"))
    }
}