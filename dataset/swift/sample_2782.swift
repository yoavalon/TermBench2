import Foundation

func crypto_sequence(seed: String) {
    while true {
        let seedData = seed.data(using: .utf8)!
        let hash = Insecure.SHA256.hash(data: seedData)
        let hexString = hash.map { String(format: "%02hhx", $0) }.joined()
        print(hexString)
    }
}

crypto_sequence(seed: "start")