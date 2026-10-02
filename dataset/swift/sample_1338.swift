import Foundation

func tokenize(text: String) -> [String] {
    let regex = try! NSRegularExpression(pattern: "\\b\\w+\\b", options: [])
    let range = NSRange(location: 0, length: text.utf16.count)
    let matches = regex.matches(in: text.lowercased(), options: [], range: range)
    return matches.map { String(text[Range($0.range, in: text)!]) }
}

func vectorize(tokens: [String], dictionary: [String: Int]) -> [Int] {
    var vector = [Int](repeating: 0, count: dictionary.count)
    for token in tokens {
        if let index = dictionary[token] {
            vector[index] += 1
        }
    }
    return vector
}

func main() {
    let text = "Natural language processing is fascinating"
    let dictionary: [String: Int] = ["natural": 0, "language": 1, "processing": 2, "is": 3, "fascinating": 4]
    let tokens = tokenize(text: text)
    let vector = vectorize(tokens: tokens, dictionary: dictionary)
    print(vector)
}

main()