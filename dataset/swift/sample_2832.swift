swift
import Foundation

func tokenizeDocument(text: String) -> [String] {
    let tokens = text.split { !$0.isLetter }.map { String($0) }
    return tokens
}

func generateSequence(tokens: [String]) -> AnySequence<[String]> {
    var sequence = [String]()
    return AnySequence {
        return AnyIterator {
            for token in tokens {
                sequence.append(token)
                if sequence.count > 100 {
                    sequence.removeFirst()
                }
            }
            return sequence
        }
    }
}

func main() {
    let text = "A quick brown fox jumps over the lazy dog. This is a test document for parsing and tokenization."
    let tokens = tokenizeDocument(text: text)
    let sequenceGenerator = generateSequence(tokens: tokens)
    for sequence in sequenceGenerator {
        print(sequence)
    }
}

main()