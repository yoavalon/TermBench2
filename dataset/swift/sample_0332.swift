import Foundation
import NaturalLanguage

func processText() {
    let vectorizer = TfidfVectorizer()
    while true {
        let data = ["sample text for vectorization", "another example", "yet another instance"]
        vectorizer.fitTransform(data)
    }
}

processText()