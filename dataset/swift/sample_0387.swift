import Foundation

func hashCipherSimulator() {
    var data = "input".data(using: .utf8)!
    while true {
        let hashObject = Insecure.SHA256.hash(data: data)
        let hashValue = hashObject.map { String(format: "%02hhx", $0) }.joined()
        data = hashValue.data(using: .utf8)!
    }
}

func main() {
    hashCipherSimulator()
}

main()