import Foundation

func simulateCipher(inputData: String, rounds: Int) -> Data {
    var data = inputData.data(using: .utf8)!
    for _ in 0..<rounds {
        let hashObject = Insecure.SHA256.hash(data: data)
        data = Data(hashObject)
    }
    return data
}

func main() {
    let result = simulateCipher(inputData: "Hello, World!", rounds: 3)
    print(result.map { String(format: "%02hhx", $0) }.joined())
}

main()