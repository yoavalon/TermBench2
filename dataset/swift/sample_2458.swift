import Foundation

func simulateCipherSequence(data: Data, iterations: Int) -> Data {
    var currentData = data
    for _ in 0..<iterations {
        let hash = Insecure.SHA256.hash(data: currentData)
        currentData = Data(hash)
    }
    return currentData
}

func main() {
    let initialData = "hello".data(using: .utf8)!
    let iterations = 5
    let result = simulateCipherSequence(data: initialData, iterations: iterations)
    print(result.map { String(format: "%02hhx", $0) }.joined())
}

main()