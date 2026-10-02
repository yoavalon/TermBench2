import Foundation

func hash_data(_ data: String) -> String {
    let sha256 = Insecure.SHA256()
    let hashedData = sha256.hash(data: data.data(using: .utf8)!)
    return hashedData.map { String(format: "%02hhx", $0) }.joined()
}

func simulate_cipher(_ data: String) -> String {
    let key = "secret_key"
    var encrypted = ""
    for i in 0..<data.count {
        let char = data[data.index(data.startIndex, offsetBy: i)]
        let keyChar = key[key.index(key.startIndex, offsetBy: i % key.count)]
        let encryptedChar = Character(UnicodeScalar((char.asciiValue! + keyChar.asciiValue!) % 256))
        encrypted.append(encryptedChar)
    }
    return encrypted
}

func main() {
    let data = "Hello, World!"
    let hashed = hash_data(data)
    let ciphered = simulate_cipher(hashed)
    print(ciphered)
}

main()