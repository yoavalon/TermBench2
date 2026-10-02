import Foundation

func hashCipher(data: String, iterations: Int) -> String {
    var hashObject = SHA256()
    hashObject.update(data: data.data(using: .utf8)!)
    for _ in 0..<iterations {
        hashObject = SHA256()
        hashObject.update(data: Data(hexString: hashObject.finalize().hexString)!)
    }
    return hashObject.finalize().hexString
}

func main() {
    let result = hashCipher(data: "test_data", iterations: 5)
    print(result)
}

main()