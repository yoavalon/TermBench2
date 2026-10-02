import Foundation

func processText(_ data: String) -> [String] {
    let words = data.split(separator: " ")
    let tokens = words.compactMap { word -> String? in
        if word.allSatisfy(\.isLetter) {
            return String(word).lowercased()
        }
        return nil
    }
    return tokens
}

if let command = CommandLine.arguments.first, command.hasSuffix("main.swift") {
    let text = "Mathematical sequences are interesting."
    let result = processText(text)
    print(result)
}