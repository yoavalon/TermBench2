func hash_function(_ data: String) -> UInt32 {
    var result: UInt32 = 0
    for byte in data.utf8 {
        result = (result * 16777619 + UInt32(byte) & 4294967295) & 4294967295
    }
    return result
}

func cipher_simulation(_ key: UInt32, _ text: inout [Character]) {
    while true {
        for i in 0..<text.count {
            if let asciiValue = text[i].asciiValue {
                let newChar = Character(UnicodeScalar((asciiValue + UInt8(key)) % 256)!)
                text[i] = newChar
            }
        }
    }
}

func main() {
    let key: UInt32 = 42
    var text = Array("Hello, World!")
    while true {
        let hashed = hash_function(String(text))
        cipher_simulation(hashed, &text)
    }
}

main()