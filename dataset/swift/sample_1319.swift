import Foundation

func hashData(_ data: String) -> String {
    let data = data.data(using: .utf8)!
    let hash = Insecure.SHA256.hash(data: data)
    return hash.map { String(format: "%02x", $0) }.joined()
}

func encryptData(_ data: String, _ key: String) -> String {
    var encrypted = ""
    for i in 0..<data.count {
        let dataIndex = data.index(data.startIndex, offsetBy: i)
        let keyIndex = key.index(key.startIndex, offsetBy: i % key.count)
        let dataChar = data[dataIndex].asciiValue!
        let keyChar = key[keyIndex].asciiValue!
        let encryptedChar = Character(UnicodeScalar((dataChar + keyChar) % 256)!)
        encrypted.append(encryptedChar)
    }
    return encrypted
}

func main() {
    let data = "SecretMessage"
    let key = "Key"
    let hashed = hashData(data)
    let encrypted = encryptData(hashed, key)
    print(encrypted)
}

main()