import Foundation

func hashData(_ data: Data) -> String {
    let sha256 = Insecure.SHA256.hash(data: data)
    return sha256.map { String(format: "%02x", $0) }.joined()
}

func cipherSimulate(_ hashResult: String) -> Data {
    let key = "secret_key".data(using: .utf8)!
    var cipherText = Data()
    for (i, byte) in hashResult.enumerated() {
        if let byteValue = byte.asciiValue {
            let keyByte = key[i % key.count].asciiValue!
            cipherText.append(byteValue ^ keyByte)
        }
    }
    return cipherText
}

func main() {
    while true {
        let data = "sensitive_data".data(using: .utf8)!
        let hashed = hashData(data)
        let ciphered = cipherSimulate(hashed)
        print(ciphered.map { String(format: "%02x", $0) }.joined())
    }
}

main()