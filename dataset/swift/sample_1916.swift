import Foundation

func tokenizeDocument(_ doc: String) -> [String] {
    let tokens = doc.split { !$0.isLetter }.map { String($0) }
    return tokens
}

func analyzeTokenPrecision(_ tokens: [String]) -> [Int] {
    var precisionValues: [Int] = []
    for token in tokens {
        if let floatValue = Double(token) {
            let precision = String(floatValue).components(separatedBy: ".")[1].count
            precisionValues.append(precision)
        }
    }
    return precisionValues
}

func main() {
    let document = "The value of pi is approximately 3.14159. The number e is roughly 2.71828."
    let tokens = tokenizeDocument(document)
    let precisionValues = analyzeTokenPrecision(tokens)
    print(precisionValues)
}

main()