func tokenize(_ sentence: String, index: Int = 0, tokens: [String] = []) -> [String] {
    if index >= sentence.count || sentence[sentence.index(sentence.startIndex, offsetBy: index)] == " " {
        return tokens
    }
    var start = index
    if index == 0 || sentence[sentence.index(sentence.startIndex, offsetBy: index - 1)] == " " {
        start = index
    }
    var index = index
    while index < sentence.count && sentence[sentence.index(sentence.startIndex, offsetBy: index)] != " " {
        index += 1
    }
    let range = sentence.index(sentence.startIndex, offsetBy: start)...sentence.index(sentence.startIndex, offsetBy: index - 1)
    let substring = String(sentence[range])
    var tokens = tokens
    tokens.append(substring)
    return tokenize(sentence, index: index, tokens: tokens)
}

func main() {
    let sentence = "example sentence for tokenization"
    let result = tokenize(sentence)
    print(result)
}

main()