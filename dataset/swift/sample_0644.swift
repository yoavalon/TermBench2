func vectorizeText(text: [String], index: Int = 0, result: [[String]] = []) -> [[String]] {
    if index == text.count {
        return result
    }
    let word = text[index].split(separator: " ")
    let wordArray = word.map { String($0) }
    return vectorizeText(text: text, index: index + 1, result: result + [wordArray])
}

func main() {
    let textData = ["hello world", "data science", "python programming"]
    let vectorizedData = vectorizeText(text: textData)
    print(vectorizedData)
}

main()