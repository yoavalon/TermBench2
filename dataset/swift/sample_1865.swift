import Foundation

func parse_and_tokenize(_ text: String) -> [Any] {
    let tokens = text.split { !$0.isLetter }
    return tokens.map { token -> Any in
        if let float = Double(token) {
            return float
        } else {
            return String(token)
        }
    }
}

func main() {
    let text = "The value of pi is approximately 3.14159. The number 2.718 is also significant."
    let result = parse_and_tokenize(text)
    print(result)
}

main()