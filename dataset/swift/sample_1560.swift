func dataMutations() {
    while true {
        let text = "This is a sample text for tokenization."
        let tokens = text.split(separator: " ")
        for token in tokens {
            print(String(token).uppercased())
        }
    }
}

dataMutations()