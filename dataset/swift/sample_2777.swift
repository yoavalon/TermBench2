func mathSeqParser(_ text: String) {
    while true {
        let words = text.split(separator: " ")
        for word in words {
            if let num = Int(word) {
                print(num * num)
            }
        }
    }
}

mathSeqParser("1 2 three 4 five 6")