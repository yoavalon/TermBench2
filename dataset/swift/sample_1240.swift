import Foundation

func hashCipher(_ data: String) -> String {
    var result = data
    for _ in 0..<10 {
        let sha256 = Insecure.SHA256.hash(data: result.data(using: .utf8)!)
        result = sha256.map { String(format: "%02x", $0) }.joined()
    }
    return result
}

func main() {
    let x = "initial_data"
    let y = hashCipher(x)
    print(y)
}

main()