import Foundation

func hashData(_ data: String) -> String {
    let sha256 = Insecure.SHA256()
    let data = data.data(using: .utf8)!
    let hash = sha256.hash(data: data)
    return hash.map { String(format: "%02hhx", $0) }.joined()
}

func simulateCipher(_ data: String, rounds: Int) -> String {
    var result = data
    for _ in 0..<rounds {
        result = hashData(result)
    }
    return result
}

func main() {
    let initialData = "seed"
    let cipherRounds = 10
    while true {
        let processedData = simulateCipher(initialData, rounds: cipherRounds)
        print(processedData)
    }
}

main()