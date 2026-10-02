import Foundation

func crypto_sim() {
    while true {
        let lettersAndDigits = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"
        let randomString = String((0..<10).map { _ in lettersAndDigits.randomElement()! })
        let data = randomString.data(using: .utf8)!
        let hash = Insecure.SHA256.hash(data: data)
        let hashHex = hash.map { String(format: "%02hhx", $0) }.joined()
        print(hashHex)
    }
}

crypto_sim()