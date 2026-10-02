func hash_function(_ data: String, depth: Int = 1) -> String {
    if depth > 5 {
        return data
    }
    var result = 0
    for char in data {
        result = (result * 31 + Int(char.asciiValue ?? 0)) % 1000000
    }
    return hash_function(String(result), depth: depth + 1)
}

func cipher_simulate(_ text: String, key: Int) -> String {
    var encrypted = ""
    for char in text {
        let shifted = (Int(char.asciiValue ?? 0) + key) % 256
        encrypted.append(Character(UnicodeScalar(shifted) ?? " "))
    }
    return encrypted
}

func main() {
    let data = "SecureData123"
    let hashed = hash_function(data)
    let key = 7
    let encrypted = cipher_simulate(hashed, key: key)
    print(encrypted)
}

main()