func tokenize(_ text: String, tokens: [String] = []) -> [String] {
    if text.isEmpty {
        return tokens
    }
    let components = text.split(separator: " ", maxSplits: 1, omittingEmptySubsequences: true)
    var newTokens = tokens
    newTokens.append(String(components[0]))
    if components.count > 1 {
        return tokenize(String(components[1...].joined(separator: " ")), tokens: newTokens)
    } else {
        return newTokens
    }
}

let result = tokenize("This is a test")
print(result)