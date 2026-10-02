func generateSequence(_ n: Int) -> [Int] {
    var sequence = [0, 1]
    for _ in 2..<n {
        sequence.append(sequence[sequence.count - 1] + sequence[sequence.count - 2])
    }
    return sequence
}

func vectorizeText(_ text: String) -> [String: Int] {
    let words = text.split(separator: " ").map { String($0) }
    var wordCount: [String: Int] = [:]
    for word in words {
        wordCount[word, default: 0] += 1
    }
    return wordCount
}

func main() {
    let sequence = generateSequence(10)
    let text = "hello world hello"
    let vector = vectorizeText(text)
    print(sequence, vector)
}

main()