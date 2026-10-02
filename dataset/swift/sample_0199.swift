import Foundation

func hash_data(data: Data) -> String {
    let sha256 = Insecure.SHA256.hash(data: data)
    return sha256.map { String(format: "%02x", $0) }.joined()
}

func cipher_simulate(text: String) -> String {
    var encrypted = ""
    for char in text {
        let asciiValue = Int(char.asciiValue ?? 0)
        let encryptedChar = Character(UnicodeScalar((asciiValue + 3) % 256))
        encrypted.append(encryptedChar)
    }
    return encrypted
}

func main() {
    let data = "Hello, World!".data(using: .utf8)!
    let hashed = hash_data(data: data)
    let encrypted = cipher_simulate(text: hashed)
    print(encrypted)
}

main()