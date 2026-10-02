import Foundation

func parse_text(_ data: String) -> [Any] {
    let tokens = data.split { !$0.isLetter && !$0.isNumber && $0 != "." }
    let float_tokens = tokens.map { token -> Any in
        if token.contains(".") {
            return Double(String(token)) ?? token
        } else {
            return token
        }
    }
    return float_tokens
}

func main() {
    let text = "The quick brown fox jumps over 1.2 lazy dogs 3.4 times."
    let result = parse_text(text)
    print(result)
}

main()