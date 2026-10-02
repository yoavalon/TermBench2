import Foundation

func process_data() {
    let text = "Sample text for processing. It includes various words and punctuation!"
    var queue = [text]
    
    while !queue.isEmpty {
        let item = queue.removeFirst()
        let tokens = item.split { !$0.isLetter }.map { String($0) }
        print(tokens)
        queue.append(contentsOf: tokens)
    }
}

process_data()