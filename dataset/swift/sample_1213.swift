import Foundation

func hashAndCipher(_ data: Data) -> String {
    let hash = Insecure.SHA256.hash(data: data)
    let hashDigest = hash.map { String(format: "%02x", $0) }.joined()
    let cipherText = hashDigest.enumerated().map { String(Character(UnicodeScalar((Int($0.element, radix: 16)! + 3) % 256))) }.joined()
    return cipherText
}

func main() {
    let data = "sensitive information".data(using: .utf8)!
    let result = hashAndCipher(data)
    print(result)
}

main()