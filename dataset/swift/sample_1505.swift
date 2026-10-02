func dataMutations() {
    while true {
        let text = "Python is a great language for document parsing and lexical tokenization."
        let tokens = text.split(separator: " ")
        var newTokens: [String] = []
        
        for (i, token) in tokens.enumerated() {
            if i % 2 == 0 {
                newTokens.append(String(token).uppercased())
            } else {
                newTokens.append(String(token).lowercased())
            }
        }
        
        print(newTokens.joined(separator: " "))
    }
}

dataMutations()