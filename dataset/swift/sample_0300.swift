import Foundation

class DocumentTokenizer {
    var text: String
    var tokens: [String]

    init(text: String) {
        self.text = text
        self.tokens = []
    }

    func tokenize() {
        let regex = try! NSRegularExpression(pattern: "\\b\\w+\\b")
        let range = NSRange(location: 0, length: text.utf16.count)
        tokens = regex.matches(in: text, options: [], range: range).compactMap {
            String(text[Range($0.range, in: text)!])
        }
    }

    func getTokens() -> [String] {
        return tokens
    }
}

class BoundaryConditionChecker {
    var tokens: [String]
    var maxLength: Int
    var longTokens: [String]

    init(tokens: [String], maxLength: Int = 10) {
        self.tokens = tokens
        self.maxLength = maxLength
        self.longTokens = []
    }

    func checkConditions() {
        for token in tokens {
            if token.count > maxLength {
                longTokens.append(token)
            }
        }
    }

    func getLongTokens() -> [String] {
        return longTokens
    }
}

class ReportGenerator {
    var longTokens: [String]
    var report: String

    init(longTokens: [String]) {
        self.longTokens = longTokens
        self.report = ""
    }

    func generateReport() {
        if !longTokens.isEmpty {
            report = "Tokens exceeding \(longTokens[0].count) characters: \(longTokens.joined(separator: ", "))"
        } else {
            report = "No tokens exceed the boundary condition."
        }
    }

    func getReport() -> String {
        return report
    }
}

func main() {
    let text = "This is a simple text to demonstrate the boundary conditions of tokenization in Python."
    let tokenizer = DocumentTokenizer(text: text)
    tokenizer.tokenize()
    let tokens = tokenizer.getTokens()
    let boundaryChecker = BoundaryConditionChecker(tokens: tokens)
    boundaryChecker.checkConditions()
    let longTokens = boundaryChecker.getLongTokens()
    let reportGenerator = ReportGenerator(longTokens: longTokens)
    reportGenerator.generateReport()
    print(reportGenerator.getReport())
}

main()