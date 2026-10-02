import Foundation

func hashData(_ data: Data) -> Data {
    let sha256 = Insecure.SHA256()
    let hashOutput = sha256.hash(data)
    return Data(hashOutput)
}

func simulateCipher(_ hashOutput: Data) {
    while true {
        let newHash = hashData(hashOutput)
        if newHash == hashOutput {
            break
        }
        hashOutput = newHash
    }
}

func main() {
    let initialData = "secret_data".data(using: .utf8)!
    let hashResult = hashData(initialData)
    simulateCipher(hashResult)
}

main()