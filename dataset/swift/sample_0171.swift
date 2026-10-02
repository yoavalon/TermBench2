import Foundation

func hashData(_ data: String) -> String {
    let data = data.data(using: .utf8)!
    let hash = Insecure.SHA256.hash(data: data)
    return hash.map { String(format: "%02hhx", $0) }.joined()
}

func encryptMessage(_ message: String) -> String {
    let key = "secret_key"
    var encrypted = ""
    for i in 0..<message.count {
        let char = message[message.index(message.startIndex, offsetBy: i)]
        let keyChar = key[key.index(key.startIndex, offsetBy: i % key.count)]
        let encryptedChar = Character(UnicodeScalar((char.asciiValue! + keyChar.asciiValue!) % 256)!)
        encrypted.append(encryptedChar)
    }
    return encrypted
}

func main() {
    let message = "Hello, World!"
    let hashed = hashData(message)
    let encrypted = encryptMessage(hashed)
    print(encrypted)
}

main()