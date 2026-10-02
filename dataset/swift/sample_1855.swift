import Foundation

func hashData(_ data: String) -> String {
    let data = data.data(using: .utf8)!
    let hash = Insecure.SHA256.hash(data: data)
    return hash.map { String(format: "%02hhx", $0) }.joined()
}

func main() {
    let data = "cryptographic_hashing"
    let hashed = hashData(data)
    print(hashed)
}

main()