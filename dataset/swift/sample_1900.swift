swift
import Foundation

func parse_text(_ text: String) -> [String] {
    let tokens = text.split { !$0.isLetter }.map { String($0) }
    let float_tokens = tokens.filter { $0.contains(".") && $0.split(separator: ".").count == 2 }
    return float_tokens
}

func main() {
    let text = "The value of pi is approximately 3.14159. The number 2.71828 is also important."
    let result = parse_text(text)
    print(result)
}

main()