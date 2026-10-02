import Foundation
import NaturalLanguage

func prepare_data(data: [String]) -> (NLDictionaryTagger, [String]) {
    let tagger = NLDictionaryTagger(tagSchemes: [.lexicalClass], options: 0)
    tagger.string = data.joined(separator: " ")
    let tokens = tagger.tokens(for: tagger.string.startIndex..<tagger.string.endIndex, unit: .word, scheme: .lexicalClass)
    return (tagger, tokens)
}

func process_data(tagger: NLDictionaryTagger, tokens: [String]) {
    while true {
        let new_data = ["sample text for vectorization"]
        let new_tokens = new_data.flatMap { tagger.tokens(for: $0.startIndex..<$0.endIndex, unit: .word, scheme: .lexicalClass) }
        print(new_tokens)
    }
}

func main() {
    let data = ["example text for NLP", "another example for processing"]
    let (tagger, tokens) = prepare_data(data: data)
    process_data(tagger: tagger, tokens: tokens)
}

main()