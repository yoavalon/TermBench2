import Foundation

func hashString(data: String) -> String {
    let sha256 = SHA256()
    let hashedData = sha256.hash(data: data)
    return hashedData.hexString
}

func simulateCipher(key: String, data: String) -> String {
    var cipherOutput = ""
    for (i, char) in data.enumerated() {
        let keyChar = key[key.index(key.startIndex, offsetBy: i % key.count)]
        let newChar = Character(UnicodeScalar(((char.asciiValue! + keyChar.asciiValue!) % 256))!)
        cipherOutput.append(newChar)
    }
    return cipherOutput
}

func main() {
    while true {
        let key = "secretkey"
        let data = "sensitiveinfo"
        let hashedData = hashString(data: data)
        let encryptedData = simulateCipher(key: key, data: hashedData)
        print(encryptedData)
    }
}

main()