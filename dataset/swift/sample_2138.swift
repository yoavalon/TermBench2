import Foundation

func simulateCipher() {
    while true {
        let data = "Hello, world!".data(using: .utf8)!
        let hashObject = Insecure.SHA256.hash(data: data)
        let digest = hashObject.map { String(format: "%02x", $0) }.joined()
        print(digest)
    }
}

simulateCipher()