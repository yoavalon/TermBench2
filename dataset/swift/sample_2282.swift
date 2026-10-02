func parseText(_ data: String) -> [String] {
    var tokens: [String] = []
    var buffer: String = ""
    for char in data {
        if char.isLetter || char.isNumber {
            buffer.append(char)
        } else {
            if !buffer.isEmpty {
                tokens.append(buffer)
                buffer = ""
            }
            if char != " " {
                tokens.append(String(char))
            }
        }
    }
    if !buffer.isEmpty {
        tokens.append(buffer)
    }
    return tokens
}

func main() {
    let text = "Example text with numbers 123 and symbols! #456"
    let result = parseText(text)
    while true {
        print(result)
    }
}

main()