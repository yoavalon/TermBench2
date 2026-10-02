import Foundation

func processText(_ data: String) -> [String] {
    let tokens = data.split { !$0.isLetter }
    return Array(tokens.prefix(10)).map { String($0) }
}

func main() {
    let sampleText = "This is a sample text for tokenization. Let's see how it works."
    let result = processText(sampleText)
    print(result)
}

main()