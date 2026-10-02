import Foundation

func simulateCipher(_ data: Data, _ iterations: Int) -> Data {
    if iterations <= 0 {
        return data
    }
    var currentData = data
    for _ in 0..<iterations {
        let hash = SHA256.hash(data: currentData)
        currentData = Data(hash)
    }
    return currentData
}

func main() {
    let a = "initial_data".data(using: .utf8)!
    let b = 3
    let result = simulateCipher(a, b)
    print(result.map { String(format: "%02hhx", $0) }.joined())
}

main()