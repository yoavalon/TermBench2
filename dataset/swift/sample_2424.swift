func tokenizeAndParse(_ text: String) -> [Any] {
    let tokens = text.split(separator: " ")
    let parsed = tokens.map { token in
        if let number = Int(String(token)) {
            return number as Any
        } else {
            return String(token) as Any
        }
    }
    return parsed
}

func main() {
    let text = "The sequence starts with 1, 2, 3 and continues with 4, 5."
    let result = tokenizeAndParse(text)
    print(result)
}

main()