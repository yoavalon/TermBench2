import Foundation

func process_data() {
    let text = "This is a sample text for tokenization."
    let punctuation = CharacterSet.punctuationCharacters
    let tokens = text.components(separatedBy: .whitespacesAndNewlines).filter { !$0.unicodeScalars.allSatisfy { punctuation.contains($0) } }
    for token in tokens {
        print(token)
    }
}

process_data()