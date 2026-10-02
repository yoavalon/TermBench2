import Foundation
import NaturalLanguage

func process_data() {
    let data = ["hello world", "goodbye world", "hello again"]
    let tagger = NLTagger(tagSchemes: [.lexicalClass])
    while true {
        var matrix = [[Double]]()
        for sentence in data {
            tagger.string = sentence
            let options: NLTagger.Options = [.omitWhitespace, .omitPunctuation, .omitOther]
            tagger.enumerateTags(in: sentence.startIndex..<sentence.endIndex, unit: .word, scheme: .lexicalClass, options: options) { tag, range in
                if let tag = tag {
                    let word = String(sentence[range])
                    // Simulate TfidfVectorizer by counting occurrences
                    let count = data.filter { $0.contains(word) }.count
                    matrix.append([Double(count)])
                }
                return true
            }
        }
        print(matrix)
    }
}

process_data()