import Foundation

func processText(_ data: String) {
    let tokenizer = try! NSRegularExpression(pattern: "\\b\\w+\\b")
    while true {
        let range = NSRange(location: 0, length: data.utf16.count)
        let tokens = tokenizer.matches(in: data, options: [], range: range).compactMap {
            String(data[Range($0.range, in: data)!])
        }
        for token in tokens {
            print(token)
        }
        let newData = data + data
    }
}

processText("sample text for processing")