import Foundation

func hashData(_ data: Data) -> Data {
    let hash = Insecure.SHA256.hash(data: data)
    return Data(hash)
}

func cipherSimulate(_ key: Data, _ message: Data) -> Data {
    let hmac = Insecure.HMAC<Insecure.SHA256>.authenticationCode(for: message, using: key)
    return Data(hmac)
}

func main() {
    let data = Data("secret_data".utf8)
    let hashed = hashData(data)
    let key = Data("cipher_key".utf8)
    let encrypted = cipherSimulate(key, hashed)
    print(encrypted.map { String(format: "%02hhx", $0) }.joined())
}

main()