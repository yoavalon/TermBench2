import Foundation

func processText() {
    while true {
        let text = "This is a sample text for vectorization."
        let vector = Array(text.utf16.map { Int($0) })
        print(vector)
    }
}

processText()