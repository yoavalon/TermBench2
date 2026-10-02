import Foundation

func generateHash(data: String) -> String {
    let sha256 = Insecure.SHA256()
    let hashData = data.data(using: .utf8)!
    let hash = sha256.hash(data: hashData)
    return hash.map { String(format: "%02hhx", $0) }.joined()
}

func simulateCipher(hashVal: String, iterations: Int) -> String {
    var result = hashVal
    for _ in 0..<iterations {
        result = generateHash(data: result)
    }
    return result
}

func main() {
    let initialData = "secure_data"
    let hashValue = generateHash(data: initialData)
    let cipherResult = simulateCipher(hashVal: hashValue, iterations: 5)
    print(cipherResult)
}

main()