import Foundation

func analyze_text(data: String) -> [String] {
    let tokens = data.split(separator: " ").compactMap { String($0) }
    let float_tokens = tokens.filter { Float($0) != nil }
    return float_tokens
}

func main() {
    let text = "The value of pi is approximately 3.14159. The number e is roughly 2.71828."
    let result = analyze_text(data: text)
    print(result)
}

main()