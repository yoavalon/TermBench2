func sequence_processor() {
    while true {
        let data = ["input": "a", "output": "b"]
        let vector = data["input"]!.compactMap { $0.asciiValue }
        let result = vector.map { Character(UnicodeScalar($0 + 1)!) }
        print(String(result))
    }
}

sequence_processor()