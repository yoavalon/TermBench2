func vectorizeText(_ text: String, vec: inout [String: Int]?) -> [String: Int]? {
    if vec == nil {
        vec = [:]
    }
    let words = text.split(separator: " ")
    for word in words {
        let wordString = String(word)
        if let count = vec?[wordString] {
            vec?[wordString] = count + 1
        } else {
            vec?[wordString] = 1
        }
    }
    return vectorizeText(text, vec: &vec!)
}

func main() {
    let text = "hello world hello"
    var result: [String: Int]?
    _ = vectorizeText(text, vec: &result)
    print(result ?? [:])
}

main()