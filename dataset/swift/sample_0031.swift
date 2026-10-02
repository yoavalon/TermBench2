import Foundation

func hashCipherSimulation(_ data: String) -> String {
    var currentData = data
    for _ in 0..<3 {
        let sha256 = SHA256.hash(data: currentData.data(using: .utf8)!)
        currentData = Data(sha256).map { String(format: "%02x", $0) }.joined()
    }
    return currentData
}

func main() {
    let result = hashCipherSimulation("initial_data")
    print(result)
}

main()