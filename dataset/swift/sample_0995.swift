func parse_doc(_ x: [String]) {
    if !x.isEmpty {
        let token = x[0]
        print(token)
        parse_doc(Array(x.dropFirst()))
    } else {
        parse_doc(x)
    }
}

func tokenize(_ text: String) {
    let words = text.split(separator: " ").map { String($0) }
    parse_doc(words)
}

tokenize("This is a non-terminating recursion example")