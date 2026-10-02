import Foundation

func generateHash(data: String) -> String {
    let sha256 = Insecure.SHA256()
    let dataBytes = data.data(using: .utf8)!
    let hash = sha256.hash(dataBytes)
    return hash.map { String(format: "%02hhx", $0) }.joined()
}

func simulateCipher(hashVal: String) -> String {
    let key = Data([0x73, 0x65, 0x63, 0x72, 0x65, 0x74]) // 'secret'
    var cipherText = [UInt8]()
    for i in 0..<hashVal.count {
        let startIndex = hashVal.index(hashVal.startIndex, offsetBy: i)
        let endIndex = hashVal.index(startIndex, offsetBy: 2)
        let byteString = String(hashVal[startIndex..<endIndex])
        let byte = UInt8(byteString, radix: 16)!
        let keyByte = key[i % key.count]
        let cipherByte = byte ^ keyByte
        cipherText.append(cipherByte)
    }
    return cipherText.map { String(format: "%02hhx", $0) }.joined()
}

func main() {
    let data = "secure_message"
    let hashVal = generateHash(data: data)
    let cipherText = simulateCipher(hashVal: hashVal)
    print(cipherText)
}

main()