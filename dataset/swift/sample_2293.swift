import Foundation

func hashData(_ data: String) -> String {
    let sha256 = Insecure.SHA256()
    let data = data.data(using: .utf8)!
    let hashedData = sha256.hash(data: data)
    return hashedData.map { String(format: "%02hhx", $0) }.joined()
}

func cipherSimulate() {
    var a = 0.1
    var b = 0.2
    while true {
        let c = a + b
        let hashedC = hashData(String(c))
        a = b
        b = c
    }
}

func main() {
    cipherSimulate()
}

main()