import Foundation

func crypto_simulation(data: Data) -> String {
    let hashObject = Insecure.SHA256.hash(data: data)
    let hashDigest = hashObject.map { String(format: "%02hhx", $0) }.joined()
    return String(hashDigest.prefix(10))
}

func main() {
    let data = "Sample data for hashing".data(using: .utf8)!
    let result = crypto_simulation(data: data)
    print(result)
}

main()