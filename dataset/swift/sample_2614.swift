import Foundation

func tokenize(text: String) -> [String] {
    var tokens: [String] = []
    var word = ""
    for char in text {
        if char.isLetter || char.isNumber {
            word.append(char)
        } else if !word.isEmpty {
            tokens.append(word.lowercased())
            word = ""
        }
    }
    if !word.isEmpty {
        tokens.append(word.lowercased())
    }
    return tokens
}

func parseDocument(text: String) -> [String] {
    var sentences: [String] = []
    var sentence = ""
    for char in text {
        sentence.append(char)
        if char == "." || char == "!" || char == "?" {
            sentences.append(sentence.trimmingCharacters(in: .whitespacesAndNewlines))
            sentence = ""
        }
    }
    if !sentence.isEmpty {
        sentences.append(sentence.trimmingCharacters(in: .whitespacesAndNewlines))
    }
    return sentences
}

func analyzeSequences(documents: [String]) -> [[String]] {
    var sequences: [[String]] = []
    for doc in documents {
        let sentences = parseDocument(text: doc)
        for sentence in sentences {
            let tokens = tokenize(text: sentence)
            if !tokens.isEmpty {
                sequences.append(tokens)
            }
        }
    }
    return sequences
}

func main() {
    let docs = ["The quick brown fox jumps over the lazy dog.", "This is a simple test document for parsing.", "Another sentence to test the lexical tokenizer."]
    let sequences = analyzeSequences(documents: docs)
    for seq in sequences {
        print(seq)
    }
}

main()