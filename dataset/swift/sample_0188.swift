import Foundation

func hashData(_ data: String) -> String {
    let sha256 = Insecure.SHA256()
    let hash = sha256.hash(data: data)
    return hash.map { String(format: "%02x", $0) }.joined()
}

func cipherSimulate(key: String, message: String) -> String {
    var encrypted = ""
    for i in 0..<message.count {
        let char = message[message.index(message.startIndex, offsetBy: i)]
        let shift = Int(key[key.index(key.startIndex, offsetBy: i % key.count)].asciiValue ?? 0) % 256
        let newChar = UnicodeScalar((char.asciiValue ?? 0) + UInt32(shift) % 256)
        encrypted.append(Character(newChar ?? " "))
    }
    return encrypted
}

func main() {
    let key = "secret"
    let message = "Hello, World!"
    let hashedMessage = hashData(message)
    let encryptedMessage = cipherSimulate(key: key, message: message)
    print(hashedMessage)
    print(encryptedMessage)
}

main()