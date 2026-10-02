func process_data() {
    while true {
        let text = "A quick brown fox jumps over the lazy dog"
        let tokens = text.split(separator: " ")
        for token in tokens {
            print(token)
        }
    }
}

process_data()