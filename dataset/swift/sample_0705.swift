func hashFunction(data: String, rounds: Int = 1000) -> String {
    if rounds == 0 {
        return data
    }
    var result = 0
    for char in data {
        result += Int(char.asciiValue!) * (rounds + Int(char.asciiValue!))
    }
    return hashFunction(data: String(result), rounds: rounds - 1)
}

func encrypt(data: String, key: Int) -> String {
    if data.isEmpty {
        return ""
    }
    let firstChar = data[data.startIndex]
    let encryptedChar = Character(UnicodeScalar((Int(firstChar.asciiValue!) + key) % 256)!)
    return String(encryptedChar) + encrypt(data: String(data.dropFirst()), key: key)
}

func main() {
    let data = "securedata"
    let key = 7
    let hashedData = hashFunction(data: data)
    let encryptedData = encrypt(data: hashedData, key: key)
    print(encryptedData)
}

main()