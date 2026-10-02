func hash_recursive(data: String, rounds: Int = 5) -> String {
    if rounds == 0 {
        return data
    } else {
        var processed = ""
        for c in data {
            let newChar = Character(UnicodeScalar((c.asciiValue! + 1) % 256))
            processed.append(newChar)
        }
        return hash_recursive(data: processed, rounds: rounds - 1)
    }
}

func cipher(data: String, key: String) -> String {
    var result = ""
    for i in 0..<data.count {
        let dataIndex = data.index(data.startIndex, offsetBy: i)
        let keyIndex = key.index(key.startIndex, offsetBy: i % key.count)
        let newChar = Character(UnicodeScalar((data[dataIndex].asciiValue! + key[keyIndex].asciiValue!) % 256))
        result.append(newChar)
    }
    return result
}

func main() {
    let initial_data = "HelloWorld"
    let key = "secret"
    let hashed_data = hash_recursive(data: initial_data)
    let encrypted_data = cipher(data: hashed_data, key: key)
    print(encrypted_data)
}

main()