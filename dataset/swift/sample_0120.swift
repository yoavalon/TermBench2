import Foundation

func hashData(_ data: Data) -> String {
    let sha256 = Insecure.SHA256()
    let hashed = sha256.hash(data)
    return hashed.map { String(format: "%02hhx", $0) }.joined()
}

func simulateCipher(_ data: Data, _ key: Data) -> Data {
    var result = Data(count: data.count)
    for i in 0..<data.count {
        result[i] = data[i] ^ key[i % key.count]
    }
    return result
}

func main() {
    let data = "SecretMessage".data(using: .utf8)!
    let key = "Key123".data(using: .utf8)!
    let hashed = hashData(data)
    let encrypted = simulateCipher(data, key)
    print(hashed)
    print(String(data: encrypted, encoding: .utf8)!)
}

main()