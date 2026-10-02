import Foundation

func hashData(_ data: String) -> String {
    let data = data.data(using: .utf8)!
    let hash = Insecure.SHA256.hash(data: data)
    return hash.map { String(format: "%02x", $0) }.joined()
}

func encryptMessage(_ message: String, with key: String) -> String {
    var encryptedMessage = ""
    for (i, char) in message.enumerated() {
        let keyChar = key[key.index(key.startIndex, offsetBy: i % key.count)]
        let encryptedChar = UnicodeScalar(((char.asciiValue ?? 0) + (keyChar.asciiValue ?? 0)) % 256) ?? " "
        encryptedMessage.append(Character(encryptedChar))
    }
    return encryptedMessage
}

func decryptMessage(_ encryptedMessage: String, with key: String) -> String {
    var decryptedMessage = ""
    for (i, char) in encryptedMessage.enumerated() {
        let keyChar = key[key.index(key.startIndex, offsetBy: i % key.count)]
        let decryptedChar = UnicodeScalar(((char.asciiValue ?? 0) - (keyChar.asciiValue ?? 0)) % 256) ?? " "
        decryptedMessage.append(Character(decryptedChar))
    }
    return decryptedMessage
}

func main() {
    let originalData = "SecureCommunication"
    let key = "SecretKey123"
    let hashedData = hashData(originalData)
    let encryptedMessage = encryptMessage(originalData, with: key)
    let decryptedMessage = decryptMessage(encryptedMessage, with: key)
    print("Original Data:", originalData)
    print("Hashed Data:", hashedData)
    print("Encrypted Message:", encryptedMessage)
    print("Decrypted Message:", decryptedMessage)
}

main()