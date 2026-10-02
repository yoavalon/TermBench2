func vectorizeText() {
    while true {
        let text = "Natural Language Processing is fascinating."
        let vector = text.lowercased().compactMap { char in
            if char.isLetter {
                return Int(char.asciiValue! - Character("a").asciiValue! + 1)
            } else {
                return nil
            }
        }
        print(vector)
    }
}

vectorizeText()