import Foundation

func hashData(_ data: String) -> String {
    let data = data.data(using: .utf8)!
    var digest = [UInt8](repeating: 0, count: Int(CC_SHA256_DIGEST_LENGTH))
    CC_SHA256(data, CC_LONG(data.count), &digest)
    let hash = digest.map { String(format: "%02x", $0) }.joined()
    return hash
}

func cipherSimulate(_ key: String, _ data: String) -> String {
    var encrypted = ""
    for i in 0..<data.count {
        let char = data[data.index(data.startIndex, offsetBy: i)]
        let keyChar = key[key.index(key.startIndex, offsetBy: i % key.count)]
        let encryptedChar = String(UnicodeScalar((char.asciiValue! + keyChar.asciiValue!) % 256)!)
        encrypted.append(encryptedChar)
    }
    return encrypted
}

func main() {
    let key = "secretkey"
    let data = "sensitiveinformation"
    let hashed = hashData(data)
    let encrypted = cipherSimulate(key, hashed)
    print(encrypted)
}

main()