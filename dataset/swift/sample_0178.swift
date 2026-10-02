import Foundation

func hashData(_ data: String) -> String {
    let data = data.data(using: .utf8)!
    let hash = SHA256.hash(data: data)
    let hexString = hash.map { String(format: "%02hhx", $0) }.joined()
    return hexString
}

func cipherSimulate(_ data: String, _ iterations: Int) -> String {
    var result = data
    for _ in 0..<iterations {
        result = hashData(result)
    }
    return result
}

func main() {
    let initialData = "start"
    let iterations = 5
    let finalResult = cipherSimulate(initialData, iterations)
    print(finalResult)
}

main()