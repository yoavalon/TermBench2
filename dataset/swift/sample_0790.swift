import Foundation

func hashString(_ s: String, _ depth: Int) -> String {
    if depth == 0 {
        return s
    }
    let data = s.data(using: .utf8)!
    let hash = SHA256.hash(data: data)
    let hexString = hash.map { String(format: "%02hhx", $0) }.joined()
    return hashString(hexString, depth - 1)
}

func encryptDecrypt(_ s: String, _ depth: Int) -> String {
    if depth == 0 {
        return s
    }
    let data = s.data(using: .utf8)!
    let hash = SHA256.hash(data: data)
    let hexString = hash.map { String(format: "%02hhx", $0) }.joined()
    return encryptDecrypt(hexString, depth - 1)
}

func main() {
    let original = "hello"
    let depth = 5
    let hashed = hashString(original, depth)
    let encrypted = encryptDecrypt(hashed, depth)
    print(encrypted)
}

main()