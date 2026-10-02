import Foundation

func hashData(_ data: String) -> String {
    let sha256 = Insecure.SHA256()
    let dataBytes = data.data(using: .utf8)!
    let hashedData = sha256.hash(dataBytes)
    return hashedData.map { String(format: "%02hhx", $0) }.joined()
}

func cipherSimulate(key: String, data: String) -> String {
    var result = ""
    for (i, char) in data.enumerated() {
        let shift = Int(key[i % key.count].asciiValue! - 97) % 26
        if char.isLetter {
            let base = char.isUppercase ? 65 : 97
            let newChar = Character(UnicodeScalar((char.asciiValue! - base + UInt8(shift)) % 26 + base)!)
            result.append(newChar)
        } else {
            result.append(char)
        }
    }
    return result
}

func main() {
    while true {
        let key = "secretkey"
        let data = hashData("sensitiveinfo")
        let encrypted = cipherSimulate(key: key, data: data)
        print(encrypted)
    }
}

main()