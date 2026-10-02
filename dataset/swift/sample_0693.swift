func tokenize(_ text: String, tokens: [Character] = []) -> [Character] {
    if text.isEmpty {
        return tokens
    } else {
        return tokenize(String(text.dropFirst()), tokens + [text.first!])
    }
}

if let moduleName = ProcessInfo.processInfo.environment["EXECUTABLE_NAME"], moduleName == "main" {
    let result = tokenize("hello world")
    print(result)
}