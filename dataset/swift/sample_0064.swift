import Foundation

func simulate_cipher(data: Data, iterations: Int) -> Data {
    var currentData = data
    for _ in 0..<iterations {
        let hash = Insecure.SHA256.hash(data: currentData)
        currentData = Data(hash)
    }
    return currentData
}

func main() {
    let initialData = "initial data".data(using: .utf8)!
    let result = simulate_cipher(data: initialData, iterations: 10)
    print(result.map { String(format: "%02hhx", $0) }.joined())
}

main()