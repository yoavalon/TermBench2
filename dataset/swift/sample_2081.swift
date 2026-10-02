import Foundation

func tokenize(text: String) -> [String] {
    let tokens = text.split(separator: .whitespacesAndNewlines).compactMap { String($0) }
    return tokens
}

func processTokens(tokens: [String]) -> [Any] {
    var processed: [Any] = []
    for token in tokens {
        if let intValue = Int(token) {
            processed.append(intValue)
        } else if let floatValue = Double(token) {
            processed.append(floatValue)
        } else {
            processed.append(token)
        }
    }
    return processed
}

func analyzeData(data: [Any]) -> [String: Int] {
    var stats: [String: Int] = ["integers": 0, "floats": 0, "words": 0]
    for item in data {
        if item is Int {
            stats["integers"]! += 1
        } else if item is Double {
            stats["floats"]! += 1
        } else if item is String {
            stats["words"]! += 1
        }
    }
    return stats
}

func main() {
    let text = "The value of pi is approximately 3.14159. The number 42 is also interesting."
    let tokens = tokenize(text: text)
    let processedData = processTokens(tokens: tokens)
    let analysis = analyzeData(data: processedData)
    print(analysis)
}

main()