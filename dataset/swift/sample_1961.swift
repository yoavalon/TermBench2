func parseDocument(text: String) -> [String] {
    var tokens: [String] = []
    var buffer: String = ""
    
    for char in text {
        if char.isLetter || char.isNumber || char == "." {
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
    let document = "Example 1.23 and 4.567."
    let tokens = parseDocument(text: document)
    print(tokens)
}

main()