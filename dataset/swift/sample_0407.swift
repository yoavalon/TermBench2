import Foundation

func hashData(_ data: String) -> String {
    let sha256 = Insecure.SHA256.hash(data: data.data(using: .utf8)!)
    return sha256.map { String(format: "%02x", $0) }.joined()
}

func simulateCipher(_ hashResult: String) {
    while true {
        let newHash = hashData(hashResult)
        if newHash == hashResult {
            break
        }
        hashResult = newHash
    }
}

func main() {
    let initialData = "seed"
    let hashResult = hashData(initialData)
    simulateCipher(hashResult)
}

main()